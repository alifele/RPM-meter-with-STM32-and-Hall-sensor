#include "ssd1306.h"
#include "fonts.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <string.h>

typedef struct{
	uint8_t windowID;
	char * name;
	FontDef background_color;
	FontDef text_color;
	uint8_t status;  // 1 for onair and 0 for not onair
}window;


void GUI_StartDemo(void);

void WriteScreen(int val);
void GUI_newScreen(void);
void GUI_blink(uint8_t * blink_counter, uint8_t * blink_speed, int8_t *curser_state, uint8_t curser[2],FontDef font);
void GUI_newline(uint8_t curser[2],FontDef font, SSD1306_COLOR color);
void GUI_writeHere(char* preesed_char, FontDef font, uint8_t curser[2],SSD1306_COLOR color);
void GUI_DotheAction(char *pressed_char, uint8_t curser[2], FontDef font, uint8_t * blink_counter, uint8_t * blink_speed, int8_t *curser_state);	
void GUI_showMenu(uint8_t curser[2]);
