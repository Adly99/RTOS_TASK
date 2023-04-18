#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_

#define TMR_TMR0_NORMAL_MODE            1
#define TMR_TMR0_CTC_MODE               2
#define TMR_TMR0_FAST_PWM_MODE          3


/* TIMER0 */
void TMR_timer0Init                 (void);
void TMR_timer0start                (void);
//void TMR_timer0stop                 (void);
void TMR_timer0SetCompareMatchValue (u8 OCR0_Value);
void TMR_timer0_CTC_SetCallBack     (void(*ptr)(void));


#endif /* TMR_INTERFACE_H_ */