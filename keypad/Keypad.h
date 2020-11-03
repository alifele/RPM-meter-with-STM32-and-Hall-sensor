#include "stm32f1xx_hal.h"
#include <stdbool.h>




typedef struct{
	
	// we will scan these pins to find which one is 1 --> so these pins are connected to input of micro
	GPIO_TypeDef * COL0_port;
	GPIO_TypeDef * COL1_port;
	GPIO_TypeDef * COL2_port;
	GPIO_TypeDef * COL3_port;
	
	
	// we will write 1 on one row (keeping the other rows 0) --> so these pins are connected to the output of micro
	GPIO_TypeDef * ROW0_port;
	GPIO_TypeDef * ROW1_port;
	GPIO_TypeDef * ROW2_port;
	GPIO_TypeDef * ROW3_port;
	GPIO_TypeDef * ROW4_port;
	
	
	uint16_t COL0_pin;
	uint16_t COL1_pin;
	uint16_t COL2_pin;
	uint16_t COL3_pin;
	
	uint16_t ROW0_pin;
	uint16_t ROW1_pin;
	uint16_t ROW2_pin;
	uint16_t ROW3_pin;
	uint16_t ROW4_pin;

	
} keypad_typedef;


void keypad_init(keypad_typedef * keypad_struct);
void keypad_read(bool key[20]);
char * keypad_getchar(bool keys[20]);

void keypad_setROW(uint8_t row_number);






