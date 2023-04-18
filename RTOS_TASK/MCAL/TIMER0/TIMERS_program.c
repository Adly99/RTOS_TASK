#include "..\LIB\std_types.h"
#include "..\LIB\bit_math.h"
#include "..\LIB\ERR_TYPE.h"
#include "TIMERS_interface.h"
#include "TIMERS_register.h"
#include "TIMERS_config.h"
#include "TIMERS_private.h"

static void (*Timer0_pvCompMatchCallBackFunc)(void) = NULL;

void Timer0_voidInit(void)
{
	/*Initialize waveform generation mode to work as CTC mode*/
	CLEAR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Set the required compare match value*/
	OCR0 = TIMER0_u8COMP_MATCH_VAL;

	/*Timer0 Compare match interrupt enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*Set the required prescaler*/
	TCCR0 &= TIMER0_PRESCALER_MASK;
	TCCR0 |= TIMER0_u8PRESCALER;
}

u8 Timer0_u8CompMatchSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState= OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		Timer0_pvCompMatchCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState= NULL_POINTER;
	}

	return Local_u8ErrorState;
}



/*Timer0 Compare match ISR*/
void __vector_10 (void)		__attribute__((signal));
void __vector_10 (void)
{
	if(Timer0_pvCompMatchCallBackFunc != NULL)
	{
		Timer0_pvCompMatchCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}


