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
struct my_struct Sensor;
struct flags Lock;


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
	scanf("%hd",&Sensor.AdcInput);
	
	if(Lock.ApplyHysterysis == false){
		printf("Enter upper limit lower range:\n");
		scanf("%hd",&Sensor.UpperLimit);
		printf("Enter lower limit upper range:\n");
		scanf("%hd",&Sensor.LowerLimit);
	}

	//Wrong input handling-if user inputs values out of range
	
	if((Sensor.AdcInput>ADCMAX) || (Sensor.AdcInput < ADCMIN) || (Sensor.UpperLimit >O2MAX) || (Sensor.LowerLimit<O2MIN) || (Sensor.UpperLimit<UPPERLIMITMIN) ||(Sensor.LowerLimit>LOWERLIMITMAX)){
		printf("Wrong Input\n");
		Lock.flag=true;
	}
	else{
		Lock.flag=false;
	}


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

void Scaling(struct my_struct *ptr){
	
	(ptr->AdcInput)=Sensor.AdcInput;
	(ptr->O2Conc)  =Sensor.O2Conc;
	
	ptr->O2Conc= ((O2MAX-O2MIN)/(ADCMAX-ADCMIN))*(ptr->AdcInput)+O2MIN;
	ptr->O2Conc=(ADCMAX-ADCMIN)*10;
	ptr->O2Conc=(ptr->O2Conc)/(ptr->AdcInput);
	ptr->O2Conc=(((O2MAX-O2MIN)*10)/ptr->O2Conc);

	Sensor.AdcInput=(ptr->AdcInput);
	Sensor.O2Conc  =(ptr->O2Conc)  ;

	printf("O2Conc:%d\n",Sensor.O2Conc);
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

	if((Sensor.O2Conc>=Sensor.UpperLimit) && (Sensor.O2Conc<=O2MAX)){
		printf("Upper limit !\n");
		Sensor.Status=HIGH;
		Lock.ApplyHysterysis=true;

	}else if((Sensor.O2Conc>=O2MIN) && (Sensor.O2Conc<=Sensor.LowerLimit)){
		printf("Lower limit !\n");
		Sensor.Status=LOW;
		Lock.ApplyHysterysis=true;
	}else if((Sensor.O2Conc>Sensor.LowerLimit) && (Sensor.O2Conc<Sensor.UpperLimit)){
		printf("normal range !\n");
		Sensor.Status=NORMAL;
		Lock.ApplyHysterysis=false;
	}

	
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

	if((Sensor.Status==HIGH) && (Sensor.O2Conc<(Sensor.UpperLimit-HYST))){
		Sensor.Status=NORMAL;
		Lock.ApplyHysterysis=false;
	}else if((Sensor.Status==LOW) && (Sensor.O2Conc>(Sensor.LowerLimit+HYST))){
		Sensor.Status=NORMAL;
		Lock.ApplyHysterysis=false;
	}

	

}//Hysterysis()

// ***********************************************************************************************
// * Name :            	PrintOutputs
// * Description :     	Print Status and hysterysis variables on console
// * Called from/Freq :	called from main(), only once
// * Inputs :			None
// * OUTPUTS :			None
// * RETURN :			None
// * PROCESS :			by checking status register and hysterysis variable
// * NOTES :           	
// ***********************************************************************************************


void PrintOutputs(void){

	if(Sensor.Status==HIGH){

		printf("Status:--HIGH--\n");	

	}else if(Sensor.Status==LOW){

		printf("Status:--LOW--\n");

	}else if (Sensor.Status==NORMAL)
	{
		printf("Status:--NORMAL--\n");
	}

	printf("Status:%d\n",Sensor.Status);
	printf("ApplyHysterysis:%d\n",Lock.ApplyHysterysis);
	printf("-----------------------------------------\n");


}

//[EOF]