#include <Port3.h>
#include "msp.h"
#include "LED.h"



extern uint16_t FallingEdgeCount;

void InitializePort3(void){

    // Configure P3.3 as an input
        // ** a port is input when DIR is 0
    P3->DIR &= (~0x08);


    // Enable pull-up/pull-down resistors
        //**PxREN set to 1 to enable pull-up or pull-down resistors
    P3->REN |= (0x08);


    // Select pull-up resistors
        //**PxOUT decides whether its pull-up(1) or pull-down(0)
    P3->OUT |= (0x08);


    // Select falling-edge interrupt
        //** PxIES determines interrupt edge select -> 0 = low-to-high; 1 = high-to-low
    P3->IES |= (0x08);


    // Enable interrupt for P3.3
        //** PxIE -> 0=disabled; 1 = enabled
    P3->IE |= (0x08);

    // Set NVIC enable for Port 3 with a priority of 4
    NVIC->ISER[1] |= (0x00000001 << 5); // Enables interrupts. // this is either ISER 0 or ISER 1 (technically it should be PORT3_IRQn of ISER1 but since that would be 37 the shift count too large
    NVIC->IP[(PORT3_IRQn)] = ((NVIC->IP[(PORT3_IRQn)] & 0x00) | (4 << 5)); // CORRECT(ish)

        //** IPR9 register: bit 13-15 is priorty interrupt 37 //



    // Configure 4.0 as an output
        // ** a port is output when DIR is 1
    P4->DIR |= 0x01;

 ////////////////////////////   // Write software to generate a falling-edge on P4.0 to emulate the sensor input to P3.3



}



void PORT3_IRQHandler(void){
    // Develop and verify an Interrupt Service Routine (ISR) for Port 3 that counts the number of falling edges on P3.3


    // I have to clear interrupt flag for P3, not timer A0

    // Clear interrupt flag
  //  TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG; // clears flags
    P3->IFG &= 0;


    FallingEdgeCount++;



}
