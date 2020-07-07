/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: Heating_element.c
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#include "Main.h"
#include "Port.h"
#include "Heating_element.h"


/*////////////////////////////////////////////////////////////////////////////////////// */
/*Initializes the heater pin and set its state*/
void Heat_Init(tHeat Heater,tHeat_State State)
{
    switch(Heater)
    {
        case Heat_Res:
            GPIO_InitPortPin(HEAT_CONTROL_PORT,HEAT_PIN,GPIO_OUT);
            break;
        default:
            /*No Action*/
            break;
    }
    Heat_SetState(Heater,State);
}

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Sets the heater state*/
/*////////////////////////////////////////////////////////////////////////////////////// */
void Heat_SetState(tHeat Heater,tHeat_State State)
{
    switch(Heater)
    {
        case Heat_Res:
            GPIO_WritePortPin(HEAT_DATA_PORT,HEAT_PIN,State);
            break;
        default:
            break;

    }
}

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Gets the current state of the heater*/
/*////////////////////////////////////////////////////////////////////////////////////// */
tHeat_State Heat_GetState(tHeat Heater)
{
    tHeat_State ret = HEAT_OFF;
    switch(Heater)
    {
        case Heat_Res:
            ret = GPIO_ReadPortPin(HEAT_DATA_PORT,HEAT_PIN);
            break;
        default:
            break;
    }
    return ret;
}

void Heat_Update(void)
{

}
