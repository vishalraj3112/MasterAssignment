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


	while(1){
		TakeUserInput();		//Take ADC and upper and lower level inputs

	if(flag==false){
		Scaling();				//Scale ADC to percentage

		if(ApplyHysterysis==false){
			Alarm();				//Apply Alarm
		}else if(ApplyHysterysis==true){
			Hysterysis();			//Apply Hysterysis if applicable
		}
	
		}
	}

	return 0;


}

//[EOF]