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

struct my_struct Sensor_array[3];

s32 main(void){

	Lock.flag=true;				//has to be defined inside a function
	Lock.ApplyHysterysis=false; //has to be defined inside a function

	while(1){
		TakeUserInput();		//Take ADC and upper and lower level inputs

	if(Lock.flag==false){		//this is for checking wether the given user input is valid ,if yes, then Lock.flag remains false
		Scaling(Sensor_array);				//Scale ADC to percentage

		if(Lock.ApplyHysterysis==false){//this is meant for checking weather based on the given input, hysterysis need
										//to be applied or not, if input is in any of the bands(upper or lower) then hysterysis
										//is applied otherwise not applied.	
			Alarm();				//Apply Alarm
			PrintOutputs();
		}else if(Lock.ApplyHysterysis==true){
			Hysterysis();			//Apply Hysterysis if applicable and input in upper or lower band and used to exit
									//hysterysis.
			PrintOutputs();
		}
	
		}

	}

	return 0;


}

//[EOF]