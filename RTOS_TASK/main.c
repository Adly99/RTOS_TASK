
#include "..\HAL\LCD\lcd.h"
#include "..\HAL\LED\led.h"
#include "..\SERVICES\RTOS\RTOS_interface.h"

u8 yellflag=0; 
u8 redflag=0;
u8 greflag=0;
u8 counter=0;

void LED_YELLOW_f(void)
{	counter = 0;
	lcd_vidSendCmd(0x01);
	lcd_vidGotoRowColumn(0,0);
	lcd_vidDisplyStr("time yellow");
	 yellflag =1;
 	redflag = 0;
	greflag = 0;
	led_off(LED_GREEN);
	led_off(LED_RED);
	led_on(LED_YELLOW);
}

void LED_RED_f(void)
{
	counter = 0;
	lcd_vidSendCmd(0x01);
	lcd_vidGotoRowColumn(0,0);
	lcd_vidDisplyStr("time red");	
	 yellflag =0;
	 redflag = 1;
	 greflag = 0;
	led_off(LED_YELLOW);
	led_off(LED_GREEN);
	led_on(LED_RED);
}


void LED_GREEN_f(void)
{
	counter =0;
	lcd_vidSendCmd(0x01);
	lcd_vidGotoRowColumn(0,0);
	lcd_vidDisplyStr("time green");		
	 yellflag =0;
	 redflag = 0;
	 greflag = 1;
	led_off(LED_RED);
	led_off(LED_YELLOW);	
	led_on(LED_GREEN);
}

void lcd_task(void)
{	
	if (yellflag == 1)
	{	
		if (counter == 0 )
		{
			counter = 6;
		}
			counter--;
	}
	else if (redflag == 1)
	{	
		if (counter == 0 )
		{
			counter = 10;
		}
		counter--;
	}	
	else if (greflag == 1)
	{	
		if (counter == 0 )
		{
			counter = 6;
		}
		counter--;
	}
	lcd_vidGotoRowColumn(0,15);
	lcd_vidsendnumber(counter);

}

int main(void)
{
	lcd_vidInit();
	led_init();
	
	RTOS_u8CreateTask(0,20000,&LED_YELLOW_f,0);
	RTOS_u8CreateTask(1,20000,&LED_RED_f,5000);
	RTOS_u8CreateTask(2,20000,&LED_GREEN_f,15000);
	RTOS_u8CreateTask(3,1000,&lcd_task,2);
	lcd_vidGotoRowColumn(0,0);
	lcd_vidDisplyStr("time");
	RTOS_voidStart();
    while (1) 
    {
    }
}
