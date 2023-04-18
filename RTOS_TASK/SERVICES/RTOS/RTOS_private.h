#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct
{
	u16 Periodicity;
	void(*TaskFunc)(void);
	u8 State;
	u16 FirstDelay;
}Task_t;

static void voidScheduler(void);

#define TASK_RESUMED		0
#define TASK_SUSPENDED		1

#endif
