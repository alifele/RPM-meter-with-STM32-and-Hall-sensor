#include "GUI.h"

char* page = "numm";



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
