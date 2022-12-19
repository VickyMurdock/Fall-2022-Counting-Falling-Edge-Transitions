#ifndef TIMER32_H_
#define TIMER32_H_


#include "msp.h"
#include "Defines.h"
#include <stdbool.h>
#include "LED.h"


#define TIMER_32_PERIOD 46875


void TimeDelay(uint16_t delay, uint16_t resolution);

#endif
