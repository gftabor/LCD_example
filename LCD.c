/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
int auton = 0;


//ADD all autonomous choices
void displayAuton(){
	switch(auton){
	case 1:
		displayLCDCenteredString(0, "red auton");
		break;
	case -1:
		displayLCDCenteredString(0, "blue auton");
		break;
	case 0:
		displayLCDCenteredString(0, "ram auton");
		break;
	default:
		displayLCDCenteredString(0, "No auton");
		break;
	}
}


//DO NOT MODIFY
task LCDControl()
{
	bool noButtonsPressed = true;
	displayAuton();
	while(true){
		if(noButtonsPressed){ // only update auton if a button is pressed AND wasn't pressed previously
			switch(nLCDButtons){
			case kButtonLeft:
				auton--;
				displayAuton();
				break;
			case kButtonCenter:
				stopTask(LCDControl);
				break;
			case kButtonRight:
				auton++;
				displayAuton();
				break;
			}
		}//if
		noButtonsPressed = !nLCDButtons; //update if there is a button currently pressed
		wait1Msec(20);
	}//while
}//task


void pre_auton()
{
	bStopTasksBetweenModes = true;
	startTask(LCDControl);
}

task autonomous()
{
	stopTask(LCDControl);
	switch(auton){
	case 1:
		//redauton();
		break;
	case 0:
		//ramauton()
		break;
	case -1:
		//blueauton();
		break;
	default:
		//Don't run auton
		break;
	}
}

task usercontrol()
{
	// User control code here, inside the loop
	stopTask(LCDControl);
	while (true)
	{
		motor[port1]= 50;
		wait1Msec(50);
	}
}
