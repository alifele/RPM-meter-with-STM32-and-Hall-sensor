#include "PID.h"


/*
The parameters that we will use is:

goal_rpm -> the input of the user. local variable at GUI.c
curr_rpm -> it 120000/freq. we measure it and we can not change it.

goal_dutycycle -> we don't have this parameter. it is unkown and "curr_dutycycle" will reach that by iteration
curr_dutycycle -> we calculate this with PID controller. local vatiable at PID.c

*/
int16_t Error;
int16_t Error_pre=0;
float Error_integral=0;
int16_t Error_deri=0;


uint16_t curr_dutycycle = 100;
float P = 0.01;
float I = 0.03;
float D = 0.001;
float PID_var;
float K=0.01;
uint16_t next_dutycycle;


void PID_get_nextdutycycle(uint16_t * GUI_dutycycle, uint16_t curr_RPM, uint16_t goal_RPM){
	PID_calc_dutycycle(curr_RPM, goal_RPM);
	*GUI_dutycycle = curr_dutycycle;
}

void PID_calc_dutycycle(uint16_t curr_RPM, uint16_t goal_RPM){
	
	Error =  curr_RPM - goal_RPM;
	Error_integral += Error*0.001;
	Error_deri = Error - Error_pre;
	Error_pre = Error;
	PID_var = P*Error + I*Error_integral + D*Error_deri;

	
	curr_dutycycle -= PID_var;
}




