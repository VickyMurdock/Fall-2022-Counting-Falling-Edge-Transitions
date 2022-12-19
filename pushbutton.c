
#include "pushbutton.h"
#include "msp.h"
#include "Defines.h"



void InitializePushButtonPortPin(void){


    // Configure port pin for pushbutton
    ENABLE_PULL_UP_PULL_DOWN_RESISTORS_S1;
    ENABLE_PULL_UP_PULL_DOWN_RESISTORS_S2;
    SELECT_PULL_UP_RESISTORS_S1;
    SELECT_PULL_UP_RESISTORS_S2;
    SET_PUSHBUTTON_S1_TO_AN_INPUT;
    SET_PUSHBUTTON_S2_TO_AN_INPUT;

    RISING_EDGE_INTERRUPTS_S1;
    ENABLE_SENSOR_IN_INTERRUPTS_S1;
    RISING_EDGE_INTERRUPTS_S2;
    ENABLE_SENSOR_IN_INTERRUPTS_S2;

    // Enable the interrupt in the Interrupt set enable register
        // NVIC->ISER
    NVIC->ISER[1] |= (0x00000001 << (PORT1_IRQn - 32));


    // Assign an interrupt priority in the priority register
        //NVIC->ISER
    NVIC->IP[PORT1_IRQn] = (1<<5) ;
}


void PORT1_IRQHandler(void){

    CLEAR_SENSOR_IN_INTERRUPT_FLAG_S1;
    CLEAR_SENSOR_IN_INTERRUPT_FLAG_S2;

    /*
            switch (CurrentBlinkingLED){
                 case (RED_LED_BIT):
                       TURN_OFF_RED_LED;
                       TURN_ON_GREEN_LED;
                     //turn on the red led
                       CurrentBlinkingLED = GREEN_LED_BIT;
                   break;
                 case (GREEN_LED_BIT):
                         TURN_OFF_GREEN_LED;
                         TURN_ON_RED_LED;
                         //turn on green led
                     CurrentBlinkingLED = RED_LED_BIT;
                  break;
            }
            */
}


