/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: TempSensor.c
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#include "Main.h"
#include "Port.h"
#include "Timer.h"
#include "ADC.h"
#include "TempSensor.h"

/*Macros*/
#define TEMPSENSE_PERIOD_MS      (100)

#define TEMPSENSE_N_READINGS     (10)

#define TEMPSENSE_ADC_CHANNEL    (2)

/*Variables*/
static tWord TempValue;
static tWord Avg;
/*Indicates if there is new readings in the buffer*/
static tByte TempGlobalFlag;
/*Buffer to hold the readings of the ADC*/
static tWord ReadingArr[TEMPSENSE_N_READINGS]={0};

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Initializes the temperature sensor*/
/*////////////////////////////////////////////////////////////////////////////////////// */
void TempS_Init(void)
{
    /*Initialize ADC Select prescaler 8*/
    ADC_Init(ADC_FOSC_BY_8);
    /*Measured Temperature = 0;*/
    TempValue = 0;
}

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Return the current measurement*/
/*////////////////////////////////////////////////////////////////////////////////////// */
tWord TempS_GetTemp(void)
{
    return TempValue;
}

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Return the average of the last n readings*/
/*////////////////////////////////////////////////////////////////////////////////////// */
tWord TempS_AvgReadings(void)
{
    return Avg;
}

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Checks if there is new n readings in the buffer*/
/*////////////////////////////////////////////////////////////////////////////////////// */
tByte TempS_ReadDone(void)
{
    return TempGlobalFlag;
}

/*Checks if the old readings are read*/
void TempS_CLRReadFlag(void)
{
    TempGlobalFlag = 0;
}

/*////////////////////////////////////////////////////////////////////////////////////// */
/*Temperature sensor update*/
/*////////////////////////////////////////////////////////////////////////////////////// */
void TempS_Update(void)
{
    static tWord TempSense_Counter=0;
    static tWord index = 0;
    tWord Sum = 0;

    TempSense_Counter += TMR_TICK_MS;

    if (TempSense_Counter != TEMPSENSE_PERIOD_MS){
        return;
    }

    TempSense_Counter = 0;

    /*Measure the current temperature*/
    TempValue=ADC_Convert(TEMPSENSE_ADC_CHANNEL, ADC_ADJUST_RESULT_LEFT);
    TempValue=(TempValue)/2;
    /*Assign the reading to the buffer*/
    ReadingArr[index] = TempValue;
    index++;
    /*If there were n readings in the buffer*/
    if(index == TEMPSENSE_N_READINGS)
    {
        /*Add Readings together*/
        for(index=0; index < TEMPSENSE_N_READINGS ; index++)
        {
            Sum += ReadingArr[index];
        }
        /*Calculate the average of the last n readings*/
        Avg = Sum / TEMPSENSE_N_READINGS;
        /*There is new readings*/
        TempGlobalFlag=1;
        /*make the index zero again*/
        index = 0;
    }
}
