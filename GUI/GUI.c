#include "GUI.h"
#include "keypad.h"

application_windows WINDOWS;


char* page = "numm";
uint8_t blink_speed =2;
uint8_t blink_counter =0;
int8_t curser_state = 0;
uint8_t curser[2] = {0,0};



void GUI_StartDemo(void){
	HAL_Delay(500);
	ssd1306_Fill(White);
	ssd1306_UpdateScreen();

	ssd1306_SetCursor(15,10);
	ssd1306_WriteString("Nano Tech",Font_11x18,Black);
	ssd1306_SetCursor(48,10+18+8);
	ssd1306_WriteString("Lab",Font_11x18,Black);
	ssd1306_UpdateScreen();
	HAL_Delay(500);
	ssd1306_Fill(Black);
	ssd1306_SetCursor(15,10);
	ssd1306_WriteString("Nano Tech",Font_11x18,White);
	ssd1306_SetCursor(48,10+18+8);
	ssd1306_WriteString("Lab",Font_11x18,White);
	ssd1306_UpdateScreen();
	HAL_Delay(500);
	ssd1306_Fill(White);
	ssd1306_SetCursor(15,10);
	ssd1306_WriteString("Nano Tech",Font_11x18,Black);
	ssd1306_SetCursor(48,10+18+8);
	ssd1306_WriteString("Lab",Font_11x18,Black);
	ssd1306_UpdateScreen();
	HAL_Delay(500);
	ssd1306_Fill(Black);
	ssd1306_SetCursor(15,10);
	ssd1306_WriteString("Nano Tech",Font_11x18,White);
	ssd1306_SetCursor(48,10+18+8);
	ssd1306_WriteString("Lab",Font_11x18,White);
	ssd1306_UpdateScreen();
	HAL_Delay(500);


	ssd1306_Fill(White);
	ssd1306_UpdateScreen();
	HAL_Delay(200);

	ssd1306_SetCursor(2,2);
	ssd1306_WriteString("Sharif University",Font_7x10,Black);
	ssd1306_SetCursor(1,5);
	ssd1306_WriteString("__________________",Font_7x10,Black);

	HAL_Delay(200);
	
	
	
}


void WriteScreen(int val){
	char content[10];
	 ssd1306_Fill(White);
	sprintf(content,"%d",val);
	ssd1306_SetCursor(2,2);
	ssd1306_WriteString("Sharif University",Font_7x10,Black);

	//HAL_Delay(100);

	ssd1306_SetCursor(2,32-9);
	ssd1306_WriteString("Speed:",Font_11x18,Black);


	ssd1306_WriteString(content,Font_11x18,Black);
	ssd1306_SetCursor(101,32-9+5+10);
	ssd1306_WriteString("RPM",Font_7x10,White);

	ssd1306_UpdateScreen();
	
	
}


void GUI_newScreen(void){
	ssd1306_Fill(White);
	ssd1306_SetCursor(0,0);
	ssd1306_UpdateScreen();

}

void GUI_blink(uint8_t * blink_counter, uint8_t * blink_speed, int8_t *curser_state, uint8_t curser[2], FontDef font){
	
	if((*blink_counter % *blink_speed)==0){
			if (*curser_state){
				ssd1306_SetCursor(curser[0],curser[1]);
				ssd1306_WriteString(" ",font,White);
				*curser_state = ~ *curser_state;
				ssd1306_UpdateScreen();
				//blink_counter = 1;
			}else{
				ssd1306_SetCursor(curser[0],curser[1]);
				ssd1306_WriteString(" ",font,Black);
				*curser_state = ~ *curser_state;
				ssd1306_UpdateScreen();
				//blink_counter = 1;
			}
		}
	
}

void GUI_newline(uint8_t curser[2],FontDef font, SSD1306_COLOR color){
	ssd1306_SetCursor(curser[0],curser[1]);
	ssd1306_WriteString(" ",font,color);
	curser[1] += font.FontHeight;
	curser[0] = 0;

}

void GUI_writeHere(char* preesed_char, FontDef font, uint8_t curser[2],SSD1306_COLOR color){
	ssd1306_SetCursor(curser[0],curser[1]);
	ssd1306_WriteString(preesed_char,font,color);
	//int n = sizeof(preesed_char)/sizeof(preesed_char[0]);
	//curser[0] += font.FontWidth*(n-1);
	ssd1306_GetCurser(curser);
}

/*
void GUI_DotheAction(char *pressed_char, uint8_t curser[2], FontDef font, uint8_t * blink_counter, uint8_t * blink_speed, int8_t *curser_state){
	
	if (strcmp(pressed_char, "Z")){


		switch (pressed_char[0]){
			case 'd':
				GUI_newline(curser, font, White);
				break;
			default:
					GUI_writeHere(pressed_char,font,curser, Black);  
		}

		ssd1306_UpdateScreen();

	}else{
		GUI_blink(blink_counter, blink_speed,curser_state,curser, font);
	}	

	pressed_char = "Z";
	blink_counter +=1;
}


void GUI_DotheAction_Menu(char *pressed_char, uint8_t curser[2], FontDef font, uint8_t * blink_counter, uint8_t * blink_speed, int8_t *curser_state){
	if (strcmp(page,"menu")){
		  GUI_showMenu(curser);
		  page = "menu";
	}  
}
*/


void GUI_showMenu(uint8_t curser[2]){
	curser[0] = 0;
	curser[1] = 0;
	SSD1306_COLOR background_color = Black;
	SSD1306_COLOR text_color = White;
	
	ssd1306_Fill(background_color);
	ssd1306_UpdateScreen();
	curser[1] = 2;
	GUI_writeHere("________________",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	curser[1] = 0;
	GUI_writeHere("press number:",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	curser[1] +=4;
	
	GUI_writeHere("1. set speed",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("2. program",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("3. about",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	
	ssd1306_UpdateScreen();
	
}


window GUI_router(window *win, application_windows *app){
	//uint8_t blink_speed =2;
	//uint8_t blink_counter =0;
	//int8_t curser_state = 0;
	
	WINDOWS = *app;
	

	char *pressed_char = "Z";
	bool keys[20];
	window new_window = {0};
	
	GUI_ShowWin(win);

	do{
		pressed_char = "Z";
		while(pressed_char[0] == 'Z'){
			keypad_read(keys);
			pressed_char = keypad_getchar(keys);
			//GUI_blink(&blink_counter,&blink_speed,&curser_state,curser,font)
		}
		
		new_window = GUI_DotheAction(win, pressed_char, app);
	}while(win->status);
	
	return new_window;
}



void GUI_ShowWin(window * win){
	win->status = 1;
	
	switch(win->windowID){
		/*
		case 1: //main window
			GUI_mainwin_show(win);
			break;
		*/
		
		case 2: //menu
			GUI_menu_show(win);
			break;
		
		case 3: //about
			GUI_about_show(win);
			break;
		/*
		case 4: //speed_show
			GUI_speed_show_show(win);
			break;
		
		case 5: //speed_set
			GUI_speed_set_show(win);
			break;	
		*/
	}
}


window GUI_DotheAction(window * win, char* pressed_char,application_windows *app){
	
	switch(win->windowID){
		/*
		case 1: //main window
			return GUI_mainwin_action(win, pressed_char);
			break;
		*/
		
		case 2: //menu
			return GUI_menu_action(win, pressed_char,app);
			break;
		
		case 3: //about
			return GUI_about_action(win, pressed_char,app);
			break;
		/*		
		case 4: //speed_show
			return GUI_speed_show_action(win, pressed_char);
			break;
		
		case 5: //speed_set
			return GUI_speed_set_action(win, pressed_char);
			break;	
		*/
	}
	
	
}







void GUI_menu__init__(window *win){
	
	win->windowID = 2;
	win->name = "m";
	win->background_color = Black;
	win->text_color = White;
	win->status = 0;  //Not on-air

}

void GUI_menu_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	SSD1306_COLOR background_color = Black;
	SSD1306_COLOR text_color = White;
	
	ssd1306_Fill(background_color);
	ssd1306_UpdateScreen();
	curser[1] = 2;
	GUI_writeHere("________________",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	curser[1] = 0;
	GUI_writeHere("press number:",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	curser[1] +=4;
	
	GUI_writeHere("1. set speed",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("2. program",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("3. about",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	
	ssd1306_UpdateScreen();
}


window GUI_menu_action(window *win, char * pressed_char,application_windows *app){
	curser[0] = 0;
	curser[1] = 0;
	if (strcmp(pressed_char, "Z")){
		switch (pressed_char[0]){
			case '3':
				//GUI_newline(curser, Font_7x10, White);
				win->status =0;
				return app->about;
				
				break;
			default:
				GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
		}
		ssd1306_UpdateScreen();
	}else{
		GUI_blink(&blink_counter, &blink_speed,&curser_state,curser, Font_7x10);
	}	

	pressed_char = "Z";
	
}







void GUI_about__init__(window *win){
	
	win->windowID = 2;
	win->name = "m";
	win->background_color = Black;
	win->text_color = White;
	win->status = 0;  //Not on-air

}

void GUI_about_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	SSD1306_COLOR background_color = Black;
	SSD1306_COLOR text_color = White;
	
	ssd1306_Fill(background_color);
	ssd1306_UpdateScreen();
	curser[1] = 2;
	GUI_writeHere("________________",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	curser[1] = 0;
	GUI_writeHere("Helolo there:",Font_7x10,curser,text_color);
	
	ssd1306_UpdateScreen();
}


window GUI_about_action(window *win, char * pressed_char,application_windows *app){
	curser[0] = 0;
	curser[1] = 0;
	if (strcmp(pressed_char, "Z")){
		switch (pressed_char[0]){
			case 'd':
				win->status = 0;
			default:
				GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
		}
		ssd1306_UpdateScreen();
	}else{
		GUI_blink(&blink_counter, &blink_speed,&curser_state,curser, Font_7x10);
	}	

	pressed_char = "Z";
	
}

/*

void GUI_mainwin__init__(window *win){
	win->windowID = 1;
	//win->name = "M";
	win->background_color = Black;
	win->text_color = White;
	win->status = 0;  //Not on-air

}


void GUI_mainwin_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	GUI_writeHere("Hello there", Font_7x10, curser, win->text_color);
}
window * GUI_mainwin_action(window *win, char* pressed_char){
	curser[0] = 0;
	curser[1] = 0;
	if (strcmp(pressed_char, "Z")){
		switch (pressed_char[0]){
			case 'd':
				GUI_newline(curser, Font_7x10, White);
				break;
			default:
				GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
		}
		ssd1306_UpdateScreen();
	}else{
		GUI_blink(&blink_counter, &blink_speed,&curser_state,curser, Font_7x10);
	}	

	pressed_char = "Z";
	
}





void GUI_about__init__(window *win){
	
	win->windowID = 3;
	win->name = "a";
	win->background_color = Black;
	win->text_color = White;
	win->status = 0;  //Not on-air

}

void GUI_about_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	GUI_writeHere("Hello there", Font_7x10, curser, win->text_color);
}


window *GUI_about_action(window *win, char * pressed_char){
	curser[0] = 0;
	curser[1] = 0;
	if (strcmp(pressed_char, "Z")){
		switch (pressed_char[0]){
			case 'd':
				GUI_newline(curser, Font_7x10, White);
				break;
			default:
				GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
		}
		ssd1306_UpdateScreen();
	}else{
		GUI_blink(&blink_counter, &blink_speed,&curser_state,curser, Font_7x10);
	}	

	pressed_char = "Z";
	
}

void GUI_program__init__(window *win){
	
	win->windowID = 4;
	win->name = "p";
	win->background_color = White;
	win->text_color = Black;
	win->status = 0;  //Not on-air

}

void GUI_program_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	GUI_writeHere("Hello there", Font_7x10, curser, win->text_color);
}

window *GUI_program_action(window *win, char * pressed_char){
	curser[0] = 0;
	curser[1] = 0;
	if (strcmp(pressed_char, "Z")){
		switch (pressed_char[0]){
			case 'd':
				GUI_newline(curser, Font_7x10, White);
				break;
			default:
				GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
		}
		ssd1306_UpdateScreen();
	}else{
		GUI_blink(&blink_counter, &blink_speed,&curser_state,curser, Font_7x10);
	}	

	pressed_char = "Z";
	
}

void GUI_speed_show__init__(window *win){
	
	win->windowID = 5;
	win->name = "S";
	win->background_color = White;
	win->text_color = Black;
	win->status = 0;  //Not on-air

}

void GUI_speed_show_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	GUI_writeHere("Hello there", Font_7x10, curser, win->text_color);
}

window *GUI_speed_show_action(window *win, char * pressed_char){
	curser[0] = 0;
	curser[1] = 0;
	if (strcmp(pressed_char, "Z")){
		switch (pressed_char[0]){
			case 'd':
				GUI_newline(curser, Font_7x10, White);
				break;
			default:
				GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
		}
		ssd1306_UpdateScreen();
	}else{
		GUI_blink(&blink_counter, &blink_speed,&curser_state,curser, Font_7x10);
	}	

	pressed_char = "Z";
	
}

void GUI_speed_set__init__(window *win){
	
	win->windowID = 6;
	win->name = "s";
	win->background_color = White;
	win->text_color = Black;
	win->status = 0;  //Not on-air

}

void GUI_speed_set_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	GUI_writeHere("Hello there", Font_7x10, curser, win->text_color);
}

window *GUI_speed_set_action(window *win, char * pressed_char){
	curser[0] = 0;
	curser[1] = 0;
	if (strcmp(pressed_char, "Z")){
		switch (pressed_char[0]){
			case 'd':
				GUI_newline(curser, Font_7x10, White);
				break;
			default:
				GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
		}
		ssd1306_UpdateScreen();
	}else{
		GUI_blink(&blink_counter, &blink_speed,&curser_state,curser, Font_7x10);
	}	

	pressed_char = "Z";
	
}
*/


