#include <Port3.h>
#include "msp.h"
#include <stdint.h>
#include <stdbool.h>
#include "Defines.h"
#include "Clock.h"
#include "CortexM.h"
#include "LED.h"
#include "pushbutton.h"
#include "Timer32.h"



uint16_t volatile CurrentTime = 0;
uint16_t volatile PreviousTime = 0;
uint16_t volatile ElapsedTime = 0;
uint16_t Counter = 0;
uint16_t FallingEdgeCount = 0;
uint16_t volatile TestCases = 0;
uint16_t volatile TestCasesPassed = 0;


/**
 * main.c
 */
void main(void)
{

	  bool ClockSystemError = false;

	    // Stop the watchdog timer.
	    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
	    DisableInterrupts();

	    // Configure the clock system. If there is an error,
	    // continue trying to initialize.
	    ClockSystemError = InitializeClockSystem();
	    while (ClockSystemError) {
	        ClockSystemError = InitializeClockSystem();
	    }

	    // Initialize the hardware
	    InitializeLEDPortPins();
	    InitializePushButtonPortPin();
	    InitializePort3();

	    EnableInterrupts();
	    while (TRUE) {


	        TestCases++;


	        TOGGLE_4_PIN;
	        TimeDelay(500, ONE_MILLISECOND_DELAY);
	      //  WaitForInterrupt();
	        TOGGLE_4_PIN;
	        TimeDelay(500, ONE_MILLISECOND_DELAY);




	        TestCasesPassed++;

	    }
}
