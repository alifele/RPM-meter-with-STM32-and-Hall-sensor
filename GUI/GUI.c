#include "GUI.h"
#include "keypad.h"
#include <stdlib.h>

application_windows WINDOWS;


char* page = "numm";
uint8_t blink_speed =3;
uint8_t blink_counter =0;
int8_t curser_state = 0;
uint8_t curser[2] = {0,0};
uint8_t set_speed_counter=0;
extern int32_t Frequency;
uint16_t input_number = 0;
char input_string[3];


void GUI_StartDemo(void){
	
	
	
	
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


window GUI_GoTo(window *win_curr, window win_next){
	win_curr->status =0;
	return win_next;
}



window GUI_router(window *win, application_windows *app){
	//uint8_t blink_speed =2;
	//uint8_t blink_counter =0;
	//int8_t curser_state = 0;
	
	
	bool keys[20];
	char *my_char = "Z";
	//volatile int alifele = 231;
	window new_window = {0};
	
	GUI_ShowWin(win);

	do{
		my_char = "Z";
		while(my_char[0] == 'Z'){
			if (win->windowID == 1){
				GUI_show_speed_show(win);
				HAL_Delay(200);
			}
			if (win->windowID == 2){
				GUI_set_speed_blinking_show(win);
				HAL_Delay(100);
			}
			keypad_read(keys);
			my_char = keypad_getchar(keys);
			//alifele = 43423;
			//GUI_blink(&blink_counter,&blink_speed,&curser_state,curser,font);
			
		}
		
		new_window = GUI_DotheAction(win, my_char, app);
	}while(win->status);
	
	return new_window;
}



void GUI_ShowWin(window * win){
	win->status = 1;
	
	switch(win->windowID){
		
		case 0: //main window
			GUI_mainwindow_show(win);
			break;
		
		
		case 5: //menu
			GUI_menu_show(win);
			break;
		
		case 4: //about
			GUI_about_show(win);
			break;
		
		case 1: //about
			GUI_show_speed_show(win);
			break;
		
		case 2: //about
			GUI_set_speed_show(win);
			break;
		
		case 6: //about
			GUI_settingSpeed_show(win);
			break;
		
		case 7: //about
			GUI_invalid_show(win);
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
		
		case 0: //main window
			return GUI_mainwindow_action(win, pressed_char,app);
			break;
		
		
		case 5: //menu
			return GUI_menu_action(win, pressed_char,app);
			break;
		
		case 4: //about
			return GUI_about_action(win, pressed_char,app);
			break;
		
		case 1: //show speed
			return GUI_show_speed_action(win, pressed_char,app);
			break;
		
		case 2: //set speed
			return GUI_set_speed_action(win, pressed_char,app);
			break;
		
		case 6: //set speed
			return GUI_settingSpeed_action(win, pressed_char,app);
			break;
		
		case 7: //set speed
			return GUI_invalid_action(win, pressed_char,app);
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
	
	win->windowID = 5;
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
	
	GUI_writeHere("1. show speed",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("2. set speed",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("3. program",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("4. about",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	
	
	
	
	ssd1306_UpdateScreen();
}


window GUI_menu_action(window *win, char * pressed_char,application_windows *app){
	curser[0] = 0;
	curser[1] = 0;
	if (strcmp(pressed_char, "Z")){
		switch (pressed_char[0]){
			case '4':
				return GUI_GoTo(win, app->about);
				break;
			
			case '1':
				return GUI_GoTo(win, app->speed_show);
				break;
			
			case '2':
				return GUI_GoTo(win, app->speed_set);
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
	
	win->windowID = 4;
	win->name = "a";
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
	GUI_writeHere("RPM controller",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);

	
	curser[1] +=4;
	
	GUI_writeHere("designed by:",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("Ali Fele Paranj",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("Elahe Mollaheydar",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	GUI_writeHere("November 2020",Font_7x10,curser,text_color);
	GUI_newline(curser, Font_7x10,text_color);
	
	ssd1306_UpdateScreen();
}


window GUI_about_action(window *win, char * pressed_char,application_windows *app){
	curser[0] = 0;
	curser[1] = 0;
	pressed_char = "e";
	switch (pressed_char[0]){
		case 'e':
			return GUI_GoTo(win, app->menu);
		default:
			GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
	}
	ssd1306_UpdateScreen();
	
	
}








void GUI_mainwindow__init__(window *win){
	
	win->windowID = 0;
	win->name = "M";
	win->background_color = White;
	win->text_color = Black;
	win->status = 0;  //Not on-air

}

void GUI_mainwindow_show(window *win){
	
	curser[0] = 0;
	curser[1] = 0;
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
	ssd1306_SetCursor(5,10);
	ssd1306_WriteString("Press Esc...",Font_7x10,Black);
	ssd1306_UpdateScreen();
	
}


window GUI_mainwindow_action(window *win, char * pressed_char,application_windows *app){
	curser[0] = 0;
	curser[1] = 0;
	
	switch (pressed_char[0]){
		case 'e':
			return GUI_GoTo(win, app->menu);
		default:
			GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
	}
	ssd1306_UpdateScreen();
	
	
}




void GUI_show_speed__init__(window *win){
	
	win->windowID = 1;
	win->name = "s";
	win->background_color = White;
	win->text_color = Black;
	win->status = 0;  //Not on-air

}

void GUI_show_speed_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	char content[10];
	ssd1306_Fill(White);
	sprintf(content,"%d",120000/Frequency);
	
	curser[1] = 3;
	curser[0] = 1;
	GUI_writeHere("___________________",Font_7x10,curser,Black);
	GUI_newline(curser, Font_7x10,Black);
	curser[1] = 1;
	curser[0] = 4;
	GUI_writeHere("Sharif University",Font_7x10,curser,Black);
	GUI_newline(curser, Font_7x10,Black);
	
	/*
	ssd1306_SetCursor(0,7);
	GUI_writeHere("__________________",Font_7x10,curser,Black);
	GUI_newline(curser, Font_7x10,Black);
	
	ssd1306_SetCursor(0,0);
	ssd1306_WriteString("Sharif University",Font_7x10,Black);
	*/
	//HAL_Delay(100);

	ssd1306_SetCursor(2,32-9);
	ssd1306_WriteString("Speed:",Font_11x18,Black);


	ssd1306_WriteString(content,Font_11x18,Black);
	ssd1306_SetCursor(104,32-9+5+11);
	ssd1306_WriteString("RPM",Font_7x10,White);
	
	ssd1306_SetCursor(1,32-9+5+10+15);
	ssd1306_WriteString("menu: hold Esc...",Font_7x10,White);

	ssd1306_UpdateScreen();
	
}


window GUI_show_speed_action(window *win, char * pressed_char,application_windows *app){
	curser[0] = 0;
	curser[1] = 0;
	
	switch (pressed_char[0]){
		case 'e':
			return GUI_GoTo(win, app->menu);
		default:
			GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
	}
	ssd1306_UpdateScreen();
	
	
}




void GUI_set_speed__init__(window *win){
	
	win->windowID = 2;
	win->name = "S";
	win->background_color = White;
	win->text_color = Black;
	win->status = 0;  //Not on-air

}

void GUI_set_speed_show(window *win){
	set_speed_counter = 0;
	input_number = 0;
	curser[0] = 0;
	curser[1] = 0;
	char content[10];
	ssd1306_Fill(White);
	sprintf(content,"%d",120000/Frequency);
	
	curser[1] = 3;
	curser[0] = 1;
	GUI_writeHere("___________________",Font_7x10,curser,Black);
	GUI_newline(curser, Font_7x10,Black);
	curser[1] = 1;
	curser[0] = 4;
	GUI_writeHere("    Set Speed    ",Font_7x10,curser,White);
	GUI_newline(curser, Font_7x10,Black);
	
	/*
	ssd1306_SetCursor(0,7);
	GUI_writeHere("__________________",Font_7x10,curser,Black);
	GUI_newline(curser, Font_7x10,Black);
	
	ssd1306_SetCursor(0,0);
	ssd1306_WriteString("Sharif University",Font_7x10,Black);
	*/
	//HAL_Delay(100);

	ssd1306_SetCursor(2,32-9);
	ssd1306_WriteString("Speed:",Font_11x18,Black);


	//ssd1306_WriteString(content,Font_11x18,Black);
	ssd1306_SetCursor(104,32-9+5+13);
	ssd1306_WriteString("RPM",Font_7x10,White);
	
	ssd1306_SetCursor(1,32-9+5+10+15);
	ssd1306_WriteString("set:Ent, menu:Esc",Font_7x10,White);
	
	curser[0] = 68;
	curser[1] = 23;
	ssd1306_UpdateScreen();
	
}



void GUI_set_speed_blinking_show(window *win){
	//ssd1306_SetCursor(curser[0],curser[1]);
	//ssd1306_WriteString("RPM",Font_7x10,White);
	//ssd1306_UpdateScreen();
	GUI_blink(&blink_counter, &blink_speed, &curser_state, curser, Font_11x18);
	blink_counter += 1 ;
}

window GUI_set_speed_action(window *win, char * pressed_char,application_windows *app){

	switch (pressed_char[0]){
		case 'e':
			return GUI_GoTo(win, app->menu);
		
		case 'E':
			if (set_speed_counter != 0){
				input_number = conver2int(input_string);
				if (input_number >12 & input_number < 400){
					return GUI_GoTo(win, app->setting_speed);
				}else{
					return GUI_GoTo(win, app->invalid);
				}
			}
		
		default:
			if (set_speed_counter <3){
				if (pressed_char[0] >=48 & pressed_char[0] <= 58){
					GUI_writeHere(pressed_char,Font_11x18,curser, Black); 
					//curser[0] += 11;
					input_string[set_speed_counter] = pressed_char[0];
					set_speed_counter +=1;
				}	
			}
			if (set_speed_counter != 0){
				if (pressed_char[0] =='l'){ //left
					GUI_writeHere(" ",Font_11x18,curser, Black); 
					curser[0] -= 22;
					GUI_writeHere(" ",Font_11x18,curser, Black); 
					curser[0] -= 11;
					input_string[set_speed_counter] = ' ';
					set_speed_counter -=1;
				//curser[0] += 11;
				}
			}
			
	}
	ssd1306_UpdateScreen();
	
	
}

uint16_t conver2int(char *str){
	return atoi(str);
}





void GUI_settingSpeed__init__(window *win){
	
	win->windowID = 6;
	win->name = "w";
	win->background_color = White;
	win->text_color = Black;
	win->status = 0;  //Not on-air

}

void GUI_settingSpeed_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();
	ssd1306_SetCursor(9,23);
	ssd1306_WriteString("Setting",Font_11x18,White);
	HAL_Delay(100);
	ssd1306_UpdateScreen();


	ssd1306_SetCursor(9,23);
	ssd1306_WriteString("Setting.",Font_11x18,White);
	HAL_Delay(150);
	ssd1306_UpdateScreen();
	
	ssd1306_SetCursor(9,23);
	ssd1306_WriteString("Setting..",Font_11x18,White);
	HAL_Delay(200);
	ssd1306_UpdateScreen();
	
	ssd1306_SetCursor(9,23);
	ssd1306_WriteString("Setting...",Font_11x18,White);
	HAL_Delay(250);
	ssd1306_UpdateScreen();
	
	ssd1306_Fill(Black);
	ssd1306_SetCursor(9,18);
	ssd1306_WriteString("Done!      ",Font_11x18,White);
	ssd1306_SetCursor(0,45);
	ssd1306_WriteString("press Ent...",Font_7x10,White);

	ssd1306_UpdateScreen();
	
	
}


window GUI_settingSpeed_action(window *win, char * pressed_char,application_windows *app){
	curser[0] = 0;
	curser[1] = 0;
	
	switch (pressed_char[0]){
		case 'E':
			return GUI_GoTo(win, app->speed_show);
		
		default:
			GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
	}
	ssd1306_UpdateScreen();
	
	
}

void GUI_invalid__init__(window *win){
	
	win->windowID = 7;
	win->name = "w";
	win->background_color = White;
	win->text_color = Black;
	win->status = 0;  //Not on-air

}

void GUI_invalid_show(window *win){
	curser[0] = 0;
	curser[1] = 0;
	
	ssd1306_Fill(Black);

	

	
	ssd1306_Fill(Black);
	ssd1306_SetCursor(17,8);
	ssd1306_WriteString("Invalid!",Font_11x18,White);
	ssd1306_SetCursor(2,35);
	ssd1306_WriteString("12<speed<400",Font_7x10,White);
	
	ssd1306_SetCursor(2,46);
	ssd1306_WriteString("press any key...",Font_7x10,White);
	ssd1306_UpdateScreen();
	
	
}


window GUI_invalid_action(window *win, char * pressed_char,application_windows *app){
	curser[0] = 0;
	curser[1] = 0;
	pressed_char = "E";
	switch (pressed_char[0]){
		case 'E':
			return GUI_GoTo(win, app->speed_set);
		
		default:
			GUI_writeHere(pressed_char,Font_7x10,curser, Black);  
	}
	ssd1306_UpdateScreen();
	
	
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


