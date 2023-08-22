#include "APP_Includes.h"

int main(){
	u8 green = 9, yellow = 8, red = 5;
	DIO_voidInit();
	LCD_init();
	
	LCD_displayString("Remaining");
	LCD_GoToXY(0, 13);
	LCD_displayString("Sec");
	while(1){
		if(green > 0){
			LCD_GoToXY(0, 10);
			DIO_u8SetPinValue(0, 0, 1);
			LCD_display_WriteNumber(green--);
			_delay_ms(40);
		}
		else{
			DIO_u8SetPinValue(0, 0, 0);
			
			if(yellow > 0){
				LCD_GoToXY(0, 10);
				DIO_u8SetPinValue(0, 1, 1);
				LCD_display_WriteNumber(yellow--);
				_delay_ms(40);
			}
			else{
				DIO_u8SetPinValue(0, 1, 0);
				
				if(red > 0){
					LCD_GoToXY(0, 10);
					DIO_u8SetPinValue(0, 2, 1);
					LCD_display_WriteNumber(red--);
					_delay_ms(40);
				}
				else{
					DIO_u8SetPinValue(0, 2, 0);
				}
			}
		}
		
		if(green == 0 && yellow == 0 && red == 0){
			DIO_u8SetPinValue(0, 0, 0);
			DIO_u8SetPinValue(0, 1, 0);
			DIO_u8SetPinValue(0, 2, 0);
			green = 9;
			yellow = 8;
			red = 5;
		}
		

	}
	return 0;
}
