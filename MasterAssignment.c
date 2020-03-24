// ***********************************************************************************************************************
// * File Name    : MasterAssignment.c
// * Project      : Software Assignments
// * Version      : 1.0
// * Device(s)    : NA
// * Description  : Conatins scaling,alarm and hysterysis functions
// * Author       :	Vishal
// * Creation Date:	14.3.20
// ***********************************************************************************************************************

#include "MasterAssignment.h"

// *** Variable Declarations ***
s16 AdcInput,O2Conc,UpperLimit,LowerLimit;
bool flag=true;
bool ApplyHysterysis=false;
s32 Status;

//###Explanation: First the buffer size and the first elements of the buffer is taken from user


// ***********************************************************************************************
// * Name :    TakeUserInput        	
// * Description :     	Takes ADC , upper and lower sensor limit from user
// * Called from/Freq :	called from main() in while 1
// * Inputs :			None
// * OUTPUTS :			None
// * RETURN :			None
// * PROCESS :			using scanf
// * NOTES :           	
// ***********************************************************************************************

void TakeUserInput(void){


	printf("Enter ADC input:\n");
	scanf("%hd",&AdcInput);
	printf("Enter upper limit lower range:\n");
	scanf("%hd",&UpperLimit);
	printf("Enter lower limit upper range:\n");
	scanf("%hd",&LowerLimit);

	// if((AdcInput>ADCMAX) || (AdcInput < ADCMIN) || (UpperLimit >O2MAX) || (LowerLimit<O2MIN) || (UpperLimit<UPPERLIMITMIN) ||(LowerLimit>LOWERLIMITMAX)){
	// 	printf("Wrong Input\n");
	// 	flag=true;
	// }
	// else{
	// 	flag=false;
	// }

}//Take User Input

// ***********************************************************************************************
// * Name :            	Scaling
// * Description :     	Used to scale ADC input from 0-1000 to 0-30%
// * Called from/Freq :	called from main() in while 1
// * Inputs :			None
// * OUTPUTS :			None
// * RETURN :			None
// * PROCESS :			by applying scaling formulae
// * NOTES :           	
// ***********************************************************************************************

void Scaling(void){

	//O2Conc=((O2MAX-O2MIN)/(ADCMAX-ADCMIN))*AdcInput+O2MIN;
	O2Conc=(ADCMAX-ADCMIN)*10;
	O2Conc=O2Conc/AdcInput;
	O2Conc=(((O2MAX-O2MIN)*10)/O2Conc);

	printf("O2Conc:%d\n",O2Conc);

}	//Scaling

// ***********************************************************************************************
// * Name :            	Alarm
// * Description :     	Used to indicate status and alarm if applicable
// * Called from/Freq :	called from main(), only once
// * Inputs :			None
// * OUTPUTS :			None
// * RETURN :			None
// * PROCESS :			by comparing sensor value with limits
// * NOTES :           	
// ***********************************************************************************************

void Alarm(void){

	if((O2Conc>=UpperLimit) && (O2Conc<=O2MAX)){
		printf("Upper limit !\n");
		Status=HIGH;
		ApplyHysterysis=true;

	}else if((O2Conc>=O2MIN) && (O2Conc<=LowerLimit)){
		printf("Lower limit !\n");
		Status=LOW;
		ApplyHysterysis=true;
	}else{
		printf("normal range !\n");
		Status=NORMAL;
		ApplyHysterysis=false;
	}

	if(Status==HIGH){

		printf("Status:--HIGH--\n");	

	}else if(Status==LOW){

		printf("Status:--LOW--\n");

	}else if (Status==NORMAL)
	{
		printf("Status:--NORMAL--\n");
	}



	printf("Status:%ld\n",Status);
	printf("ApplyHysterysis:%d\n",ApplyHysterysis);
	printf("-------------------------------------------\n");
}//Alarm()

// ***********************************************************************************************
// * Name :            	Hysterysis
// * Description :     	Apply hysteysis lock to input
// * Called from/Freq :	called from main(), only once
// * Inputs :			None
// * OUTPUTS :			None
// * RETURN :			None
// * PROCESS :			By comparing sensor input with threshold tolerence
// * NOTES :           	
// ***********************************************************************************************

void Hysterysis(void){

	if((Status==HIGH) && (O2Conc<(UpperLimit-HYST))){
		Status=NORMAL;
		ApplyHysterysis=false;
	}else if((Status==LOW) && (O2Conc>(LowerLimit+HYST))){
		Status=NORMAL;
		ApplyHysterysis=false;
	}

	if(Status==HIGH){

		printf("Status:--HIGH--\n");	

	}else if(Status==LOW){

		printf("Status:--LOW--\n");

	}else if (Status==NORMAL)
	{
		printf("Status:--NORMAL--\n");
	}

	printf("Status:%ld\n",Status);
	printf("ApplyHysterysis:%d\n",ApplyHysterysis);
	printf("-----------------------------------------\n");


}//Hysterysis()

//[EOF]