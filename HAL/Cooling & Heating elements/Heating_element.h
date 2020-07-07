/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: Heating_element.h
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#ifndef HEATING_ELEMENT_H_INCLUDED
#define HEATING_ELEMENT_H_INCLUDED

typedef enum
{
    Heat_Res
}tHeat;

/*Heater states*/
typedef enum
{
    HEAT_OFF=0,
    HEAT_ON
}tHeat_State;

/*Functions prototypes*/
void Heat_Init(tHeat Heater,tHeat_State State);
void Heat_SetState(tHeat Heater,tHeat_State State);
tHeat_State Heat_GetState(tHeat Heater);
void Heat_Update(void);


#endif // HEATING_ELEMENT_H_INCLUDED
