#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

void Timer0_voidInit(void);

u8 Timer0_u8CompMatchSetCallBack(void (*Copy_pvCallBackFunc)(void));


#endif
