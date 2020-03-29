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

//**Define**
#define ADCMAX 1000 //24 units left for scaling
#define ADCMIN 0
#define O2MAX 30
#define O2MIN 0
#define UPPERLIMITMIN 25
#define LOWERLIMITMAX 18
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

enum state

{	
	LOW,NORMAL,HIGH
};

extern struct my_struct Sensor;
extern struct flags		Lock;


//**Function prototypes***
void TakeUserInput(void);
void Scaling(struct my_struct *ptr);
void Alarm(void); 
void Hysterysis(void);
void PrintOutputs(void);	



#endif

//[EOF]