/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Flash_interface.h"

/*Static global functions*/
static void Flash_CheckBSY_Flag(void);



void Flash_UnLock(void)
{
	/* Authorize the FLASH Registers access */
	  Flash->KEYR = FLASH_KEY_1;
    Flash->KEYR = FLASH_KEY_2;
}


void Flash_Lock(void)
{
	SET_BIT(Flash->CR,31);
}


void Flash_SetWordSize(Flash_WordSize WordSize)
{
	/*Unlcok flash*/
	Flash_UnLock();
	
	Flash->CR &= ~(0x3 << 8);
	switch(WordSize)
	{
		case FLASH_PSIZE_BYTE:
			Flash->CR &= ~(0x3 << 8);
      break;			
    case FLASH_PSIZE_HALF_WORD:
			Flash->CR |= (0x1 << 8);
      break;			
    case FLASH_PSIZE_WORD:
			Flash->CR |= (0x2 << 8);
      break;			
    case FLASH_PSIZE_DOUBLE_WORD:
			Flash->CR |= (0x3 << 8);
			break;
		default:
			break;
	}
	/*Lock flash*/
	Flash_Lock();
}


uint8 Flash_JumbAddress(uint32 Address)
{
	if(Flash_VerifyAddress(Address)==False)
	{
		return False;
	}
	else
	{
		/*No Action*/
	}
	
	Address+=1; /*Increase address by one to add thumb bit*/
	
	void(*JumbAddress)(void)=(void*)Address;
	/*Go to the address*/
	JumbAddress();
}


uint8 Flash_VerifyAddress(uint32 Address)
{
	if( (Address < FLASH_START_ADDRESS)   || (Address>FLASH_END_ADDRESS) )
	{
		return False;
	}
	else
	{
		return True;
	}
}

uint8 Flash_Write(uint32 Address , uint16 Data)
{
	if(Flash_VerifyAddress(Address)==False)
	{
		return False;
	}
	else
	{
		/*No Action*/
	}
	
	/*Wait until any running operation on flash finishes first*/
	Flash_CheckBSY_Flag();
	
	Flash_UnLock();
	/*Enable Flash programming*/
	SET_BIT(Flash->CR,0);
	
	*(volatile uint16*)Address=(uint16)Data;
	
	/*Wait until any running operation on flash finishes first*/
	Flash_CheckBSY_Flag();
	
	CLEAR_BIT(Flash->CR,0);
	Flash_Lock();
	
	return True;
}



void Flash_EraseSector(uint8 SectorNum)
{
	/*Wait until any running operation on flash finishes first*/
	Flash_CheckBSY_Flag();
  Flash_UnLock();
	SET_BIT(Flash->CR,1);
	
	if(12 <= SectorNum)
      {
        /* Bank 2 */ 
				/*This option is not for STM32F4 boards which have dual flash banks*/
        SectorNum = SectorNum + 4;
      }
      else
      {

      }

      /* Write sector number */
      Flash->CR |= ((0x1FUL <<3) & (SectorNum << 3));

      /* Start sector erase */
      SET_BIT(Flash->CR,16);
			/*Wait until any running operation on flash finishes first*/
	    Flash_CheckBSY_Flag();
			/*Clear sector erase selection bit*/
      CLEAR_BIT(Flash->CR,1);
			Flash_Lock();

}	

uint8 Flash_GetProtectionLvl(void)
{
	uint8 ProtectionStatus=0;
	volatile uint32 *pAddress = (uint32*)OPTION_BYTES_BASE_ADDRESS;
	/*Read bits from 8 to 15*/
	ProtectionStatus = (uint8)(*pAddress >> 8);
	
	return ProtectionStatus;
}



uint32 Flash_Read(uint32 Address)
{
	if(Flash_VerifyAddress(Address) == False)
	{
		return False;
	}
	else
	{
		
	}
	
	return *(volatile uint32*)Address;
}

uint8 Flash_SetProtection(Flash_Protect_state State,Flash_Protect_Lvl Level ,uint8 Sectors)
{
	/*Option byte configuration unlock*/
	Flash_OB_UnLcok();
	
	if(State == Flash_Protect_Disable)
		{
			/*Disable all r/w protection on sectors*/

			/*Wait till no active operation on flash*/
			Flash_CheckBSY_Flag();
			
			/*Clear the 31st bit (default state)*/
			Flash->OPTCR &= ~(1 << 31);

			//clear the protection : make all bits belonging to sectors as 1
			Flash->OPTCR |= (0xFF << 16);

			//Set the option start bit (OPTSTRT) in the FLASH_OPTCR register
			Flash->OPTCR |= ( 1 << 1);

			/*Wait till no active operation on flash*/
			Flash_CheckBSY_Flag();
			
			/*Option byte configuration lock*/
			Flash_OB_Lcok();
			return True;

		}
		else if(State == Flash_Protect_Enable)
		{
		    switch(Level)
         {
		    case Flash_Protect_Lvl_1:
		    	/*Check if any runing statment*/
		    	Flash_CheckBSY_Flag();
	        /*Enable Write mode*/
	       	CLEAR_BIT(Flash->OPTCR,31);
		      /*Clear used sector bits*/
		      Flash->OPTCR &= ~(Sectors << 16);
		      /*Start*/
		      SET_BIT(Flash->OPTCR,1);
		      /*Check if any runing statment*/
		    	Flash_CheckBSY_Flag();
		    	break;
		    
		    case Flash_Protect_Lvl_2:
		    	/*Check if any runing statment*/
		    	Flash_CheckBSY_Flag();
	        /*Enable Read & Write mode*/
	       	SET_BIT(Flash->OPTCR,31);
		      /*Clear sector bits*/
		      Flash->OPTCR &= ~(0xFF<<16);
		      /*Set used sector bits*/
		      Flash->OPTCR |= (Sectors << 16);
		      /*Start*/
		      SET_BIT(Flash->OPTCR,1);
		      /*Check if any runing statment*/
		    	Flash_CheckBSY_Flag();
		    	break;
		    
		    default:
		    	break;
	}
	Flash_OB_Lcok();
	
}
	
	
	return True;
	
}

void Flash_OB_UnLcok(void)
{
	Flash->OPTKEYR = FLASH_OPT_KEY1;
	Flash->OPTKEYR = FLASH_OPT_KEY2;
}

void Flash_OB_Lcok(void)
{
	SET_BIT(Flash->OPTCR,0);
}

uint32 BigToLittle_endian(uint32 Val)
{
	return (((Val>>24) & 0x000000FF) 
	    	| ((Val>>8)  & 0x0000FF00) 
	      | ((Val<<8)  & 0x00FF0000)
	      | ((Val<<24) & 0xFF000000));
}

static void Flash_CheckBSY_Flag(void)
{
	while(GET_BIT(Flash->SR,16)!=0);
}

