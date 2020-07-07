/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: Cooling_element.c
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#include "Main.h"
#include "Port.h"
#include "Cooling_element.h"

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Initialize the fan/Cooler*/
/*////////////////////////////////////////////////////////////////////////////////////// */
void Cool_Init(tCool Fan,tCool_State State)
{
    /*Switch between coolers*/
    switch(Fan)
    {
        case COOL_FAN:
            GPIO_InitPortPin(COOL_CONTROL_PORT,COOL_PIN,GPIO_OUT);
            break;
        default:
            /*No Action*/
            break;
    }
    /*Set state of the cooler*/
    Cool_SetState(Fan,State);
}

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Sets the state of the fan*/
/*////////////////////////////////////////////////////////////////////////////////////// */
void Cool_SetState(tCool Fan,tCool_State State)
{
    /*Switch between coolers*/
    switch(Fan)
    {
        case COOL_FAN:
            GPIO_WritePortPin(COOL_DATA_PORT,COOL_PIN,State);
            break;
        default:
            break;

    }
}

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Gets the current state of the fan*/
/*////////////////////////////////////////////////////////////////////////////////////// */
tCool_State Cool_GetState(tCool Fan)
{
    tCool_State ret = COOL_OFF;
    /*Switch between coolers*/
    switch(Fan)
    {
        case COOL_FAN:
            ret = GPIO_ReadPortPin(COOL_DATA_PORT,COOL_PIN);
            break;
        default:
            break;
    }
    return ret;
}


void Cool_Update(void)
{

}
