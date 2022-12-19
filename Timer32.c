#include "Timer32.h"
#include "msp.h"


void TimeDelay(uint16_t delay, uint16_t resolution){

    /* The elapsed time for the inner loop represents the period of the unit
     * time increment (such as 1 microsecond or 1 milisecond). The outer loop
     * then represents the total elapsed time in unit time increments
     */



    if (delay > 0){
        // enable the timer, selecting 32-bit size and one-shot mode

        TIMER32_1->CONTROL |= 0x00000082;
            // bit 0: set to 1 (one-shot mode)
            // bit 1: set to 1 (32-bit counter)
            // bit 7: set to 1 (timer enabled)


        // load the timer with the value for the total elapsed time
        TIMER32_1->LOAD = resolution * delay;




        // clear the interrupt flag in the status register
        TIMER32_1->INTCLR = 0x07; // 0 IFG: enabled interrupt status from the counter

        // now, poll the interrupt flag in the status register until its set
        while ((TIMER32_1->RIS & TIMER32_RIS_RAW_IFG) == 0){
        }

        // finally, dsable the timer
        TIMER32_1->CONTROL &= ~(0x00000080);
                // bit 7: set to 0 (timer disabled)


    }


}
