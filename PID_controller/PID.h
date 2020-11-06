#include "stm32f1xx_hal.h"

void PID_get_nextdutycycle(uint16_t * GUI_dutycycle, uint16_t curr_RPM, uint16_t goal_RPM);
void PID_calc_dutycycle(uint16_t curr_RPM, uint16_t goal_RPM);
