/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: TempSensor.h
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#ifndef TEMPSENSOR_H_INCLUDED
#define TEMPSENSOR_H_INCLUDED

/*Functions prototypes*/
void TempS_Init(void);
tWord TempS_GetTemp(void);
tWord TempS_AvgReadings(void);
tByte TempS_ReadDone(void);
void TempS_CLRReadFlag(void);
void TempS_Update(void);

#endif // TEMPSENSOR_H_INCLUDED
