// ***********************************************************************************************************************
// * File Name    : main.c
// * Project      : Software Assignments
// * Version      : 1.0
// * Device(s)    : NA
// * Description  : Used for calling other sub functions
// * Author       :	Vishal
// * Creation Date:	14.3.20
// ***********************************************************************************************************************

#include "MasterAssignment.h"

s32 main(void){

	Lock.flag=true;				//has to be defined inside a function
	Lock.ApplyHysterysis=false; //has to be defined inside a function

	while(1){
		TakeUserInput();		//Take ADC and upper and lower level inputs

	if(Lock.flag==false){
		Scaling();				//Scale ADC to percentage

		if(Lock.ApplyHysterysis==false){
			Alarm();				//Apply Alarm
			PrintOutputs();
		}else if(Lock.ApplyHysterysis==true){
			Hysterysis();			//Apply Hysterysis if applicable
			PrintOutputs();
		}
	
		}
	}

	return 0;


}

//[EOF]