/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: Cooling_element.h
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#ifndef COOLING_ELEMENT_H_INCLUDED
#define COOLING_ELEMENT_H_INCLUDED


typedef enum
{
    COOL_FAN
}tCool;

/*Cooler states*/
typedef enum
{
    COOL_OFF=0,
    COOL_ON
}tCool_State;

/*Functions prototypes*/
void Cool_Init(tCool Fan,tCool_State State);
void Cool_SetState(tCool Fan,tCool_State State);
tCool_State Cool_GetState(tCool Fan);
void Cool_Update(void);

#endif // COOLING_ELEMENT_H_INCLUDED
