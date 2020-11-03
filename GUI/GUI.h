#include "ssd1306.h"
#include "fonts.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <string.h>

typedef struct{
	uint8_t windowID;
	char * name;
	SSD1306_COLOR background_color;
	SSD1306_COLOR text_color;
	uint8_t status;  // 1 for onair and 0 for not onair
}window;

typedef struct{
	window mainwin;
	window menu;
	window about;
	window program;
	window speed_show;
	window speed_set;
}application_windows;


void GUI_StartDemo(void);

void WriteScreen(int val);
void GUI_newScreen(void);
void GUI_blink(uint8_t * blink_counter, uint8_t * blink_speed, int8_t *curser_state, uint8_t curser[2],FontDef font);
void GUI_newline(uint8_t curser[2],FontDef font, SSD1306_COLOR color);
void GUI_writeHere(char* preesed_char, FontDef font, uint8_t curser[2],SSD1306_COLOR color);
void GUI_showMenu(uint8_t curser[2]);


window GUI_DotheAction(window * win, char* pressed_char);
window GUI_router(window win);
void GUI_ShowWin(window * win);



void GUI_menu__init__(window *win);
void GUI_menu_show(window *win);
window GUI_menu_action(window *win, char * pressed_key);

/*
void GUI_mainwin__init__(window *win);
void GUI_mainwin_show(window *win);
window GUI_mainwin_action(window *win, char * pressed_key);

void GUI_about__init__(window *win);
void GUI_about_show(window *win);
window GUI_about_action(window *win, char * pressed_key);

void GUI_program__init__(window *win);
void GUI_program_show(window *win);
window GUI_program_action(window *win, char * pressed_key);

void GUI_speed_show__init__(window *win);
void GUI_speed_show_show(window *win);
window GUI_speed_show_action(window *win, char * pressed_key);

void GUI_speed_set__init__(window *win);
void GUI_speed_set_show(window *win);
window GUI_speed_set_action(window *win, char * pressed_key);
*/
