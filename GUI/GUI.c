#include "GUI.h"




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

