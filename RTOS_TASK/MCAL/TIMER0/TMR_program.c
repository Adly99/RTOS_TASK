/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "TMR_interface.h"
#include "TMR_config.h"



static void(*TMR_timer0_ctc_pCallBack)(void) = NULL;

/* TIMER0 */
void TMR_timer0Init(void)
{

#if TMR_TMR0_MODE == TMR_TMR0_CTC_MODE
	// Select Mode = CTC Mode
	CLEAR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	//OCR0=250 generate interrupt each 1msec
	TMR_timer0SetCompareMatchValue(250);
	
	// Enable CTC Interrupt
	SET_BIT(TIMSK,1);

	//SET PRESCALLER=64
	TMR_timer0start();
	
	
#endif
}


void TMR_timer0start(void)
{
    // Select Prescaler Value = 64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
}


void TMR_timer0stop(void)
{
	CLEAR_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
}


void TMR_timer0SetCompareMatchValue(u8 OCR0_Value)
{
	// Init Timer With Compare Value
	OCR0 = OCR0_Value;
}


void TMR_timer0_CTC_SetCallBack(void(*ptr)(void))
{
	if(ptr != NULL)
	{
		TMR_timer0_ctc_pCallBack = ptr;
	}
}


// ISR Function protoType for TMR0 CTC
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	
		//call action
		if(TMR_timer0_ctc_pCallBack != NULL)
		{
			TMR_timer0_ctc_pCallBack();
		}
		else
		{
          //nothing
		}
	
}
