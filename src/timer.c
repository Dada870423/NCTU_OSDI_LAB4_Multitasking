#include "../include/timer.h"


void local_timer_init(void)
{
	// enable timer and interrupt.
	
	// set bit 29: Interrupt enable
	// set bit 28: Timer enable
	unsigned int flag = 0x30000000;
	
	// bit 0:27: Reload value
	unsigned int reload = 100000000;
	
	*((volatile unsigned int *)LOCAL_TIMER_CONTROL_AND_STATUS) =  flag | reload;
}

void local_timer_handler(void)
{
	// clear interrupt and reload.
	// set bit 31: Interrupt flag clear when written as 1
	// set bit 30: Local timer-reloaded when written as 1
	*((volatile unsigned int *)LOCAL_TIMER_IRQ_CLR) =  0xc0000000;
}
