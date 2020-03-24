// ***********************************************************************************************************************
// * File Name    : MasterAssignment.h
// * Project      : Software Assignments
// * Version      : 1.0
// * Device(s)    : NA
// * Description  : Cotains all the relevant header and declarations of master program
// * Author       :	Vishal
// * Creation Date:	14.3.20
// ***********************************************************************************************************************

#ifndef MATER_ASSIGNMENT_H
#define MATER_ASSIGNMENT_H

//***Includes***
#include <stdio.h>
#include "myboolean.h"
#include "typedef.h"

//**Function prototypes***
void TakeUserInput(void);
void Scaling(void);
void Alarm(void); 
void Hysterysis(void);
void PrintOutputs(void);	


//**Define**
#define ADCMAX 1000 //24 units left for sacling
#define ADCMIN 0
#define O2MAX 30
#define O2MIN 0
#define UPPERLIMITMIN 25
#define LOWERLIMITMAX 18
#define LOW 0
#define HIGH 2
#define NORMAL 1
#define HYST 2
//**Extern variables**
struct my_struct
{
	s16 AdcInput;
	s16 O2Conc;
	s16 UpperLimit;
	s16 LowerLimit;
	u1 Status;

};

struct flags
{
	bool flag;
	bool ApplyHysterysis;
};

extern struct my_struct Sensor;
extern struct flags		Lock;

#endif

//[EOF]