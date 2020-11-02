#include "Keypad.h"
static keypad_typedef mykeypad_struct;

static char * keypad_keys[20] = {
	"f",
	"F",
	"#",
	"*",
	"1",
	"2",
	"3",
	"u",
	"4",
	"5",
	"6",
	"d",
	"7",
	"8",
	"9",
	"e",
	"l",
	"0",
	"r",
	"E"
};







void keypad_init(keypad_typedef * keypad_struct){
	
	mykeypad_struct = *keypad_struct;
	
	HAL_GPIO_WritePin(keypad_struct->ROW0_port, keypad_struct->ROW0_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(keypad_struct->ROW1_port, keypad_struct->ROW1_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(keypad_struct->ROW2_port, keypad_struct->ROW2_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(keypad_struct->ROW3_port, keypad_struct->ROW3_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(keypad_struct->ROW4_port, keypad_struct->ROW4_pin, GPIO_PIN_RESET);
	
}


void keypad_setROW(uint8_t row_number){
	
	switch (row_number){
		
		case 0:
			HAL_GPIO_WritePin(mykeypad_struct.ROW0_port, mykeypad_struct.ROW0_pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(mykeypad_struct.ROW1_port, mykeypad_struct.ROW1_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW2_port, mykeypad_struct.ROW2_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW3_port, mykeypad_struct.ROW3_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW4_port, mykeypad_struct.ROW4_pin, GPIO_PIN_RESET);
			break;
		
		case 1:
			HAL_GPIO_WritePin(mykeypad_struct.ROW1_port, mykeypad_struct.ROW1_pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(mykeypad_struct.ROW0_port, mykeypad_struct.ROW0_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW2_port, mykeypad_struct.ROW2_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW3_port, mykeypad_struct.ROW3_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW4_port, mykeypad_struct.ROW4_pin, GPIO_PIN_RESET);
			break;
		
		case 2:
			HAL_GPIO_WritePin(mykeypad_struct.ROW2_port, mykeypad_struct.ROW2_pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(mykeypad_struct.ROW1_port, mykeypad_struct.ROW1_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW0_port, mykeypad_struct.ROW0_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW3_port, mykeypad_struct.ROW3_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW4_port, mykeypad_struct.ROW4_pin, GPIO_PIN_RESET);
			break;
		
		case 3:
			HAL_GPIO_WritePin(mykeypad_struct.ROW3_port, mykeypad_struct.ROW3_pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(mykeypad_struct.ROW1_port, mykeypad_struct.ROW1_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW2_port, mykeypad_struct.ROW2_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW0_port, mykeypad_struct.ROW0_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW4_port, mykeypad_struct.ROW4_pin, GPIO_PIN_RESET);
			break;
		
		case 4:
			HAL_GPIO_WritePin(mykeypad_struct.ROW4_port, mykeypad_struct.ROW4_pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(mykeypad_struct.ROW1_port, mykeypad_struct.ROW1_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW2_port, mykeypad_struct.ROW2_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW3_port, mykeypad_struct.ROW3_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(mykeypad_struct.ROW0_port, mykeypad_struct.ROW0_pin, GPIO_PIN_RESET);
			break;
	}
}

void keypad_read(bool keys[20]){
	
	keypad_setROW(0);
	keys[0] = HAL_GPIO_ReadPin(mykeypad_struct.COL0_port, mykeypad_struct.COL0_pin);
	keys[1] = HAL_GPIO_ReadPin(mykeypad_struct.COL1_port, mykeypad_struct.COL1_pin);	
	keys[2] = HAL_GPIO_ReadPin(mykeypad_struct.COL2_port, mykeypad_struct.COL2_pin);	
	keys[3] = HAL_GPIO_ReadPin(mykeypad_struct.COL3_port, mykeypad_struct.COL3_pin);

	keypad_setROW(1);
	keys[4] = HAL_GPIO_ReadPin(mykeypad_struct.COL0_port, mykeypad_struct.COL0_pin);
	keys[5] = HAL_GPIO_ReadPin(mykeypad_struct.COL1_port, mykeypad_struct.COL1_pin);	
	keys[6] = HAL_GPIO_ReadPin(mykeypad_struct.COL2_port, mykeypad_struct.COL2_pin);	
	keys[7] = HAL_GPIO_ReadPin(mykeypad_struct.COL3_port, mykeypad_struct.COL3_pin);

	keypad_setROW(2);
	keys[8] = HAL_GPIO_ReadPin(mykeypad_struct.COL0_port, mykeypad_struct.COL0_pin);
	keys[9] = HAL_GPIO_ReadPin(mykeypad_struct.COL1_port, mykeypad_struct.COL1_pin);	
	keys[10] = HAL_GPIO_ReadPin(mykeypad_struct.COL2_port, mykeypad_struct.COL2_pin);	
	keys[11] = HAL_GPIO_ReadPin(mykeypad_struct.COL3_port, mykeypad_struct.COL3_pin);

	keypad_setROW(3);
	keys[12] = HAL_GPIO_ReadPin(mykeypad_struct.COL0_port, mykeypad_struct.COL0_pin);
	keys[13] = HAL_GPIO_ReadPin(mykeypad_struct.COL1_port, mykeypad_struct.COL1_pin);	
	keys[14] = HAL_GPIO_ReadPin(mykeypad_struct.COL2_port, mykeypad_struct.COL2_pin);	
	keys[15] = HAL_GPIO_ReadPin(mykeypad_struct.COL3_port, mykeypad_struct.COL3_pin);

	keypad_setROW(4);
	keys[16] = HAL_GPIO_ReadPin(mykeypad_struct.COL0_port, mykeypad_struct.COL0_pin);
	keys[17] = HAL_GPIO_ReadPin(mykeypad_struct.COL1_port, mykeypad_struct.COL1_pin);	
	keys[18] = HAL_GPIO_ReadPin(mykeypad_struct.COL2_port, mykeypad_struct.COL2_pin);	
	keys[19] = HAL_GPIO_ReadPin(mykeypad_struct.COL3_port, mykeypad_struct.COL3_pin);
	
}

char * keypad_getchar(uint8_t keynumber){
	return keypad_keys[keynumber];
}


