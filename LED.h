#ifndef LED_H
#define LED_H

#include "msp.h"

void InitializeLEDPortPins(void);

// Red LED
#define RED_LED_BIT                 0
#define RED_LED_MASK                (0x01 << RED_LED_BIT)
#define RED_LED_PORT                P1->OUT
#define RED_LED_DDR                 P1->DIR
#define SET_RED_LED_AS_AN_OUTPUT    RED_LED_DDR |= RED_LED_MASK
#define TURN_ON_RED_LED             RED_LED_PORT |= RED_LED_MASK
#define TURN_OFF_RED_LED            RED_LED_PORT &= ~RED_LED_MASK
#define TOGGLE_RED_LED              RED_LED_PORT ^= RED_LED_MASK



#define FOUR_PIN_BIT                   0
#define FOUR_PIN_MASK                 (0x01 << FOUR_PIN_BIT)
#define FOUR_PIN_PORT                 P4->OUT
#define TOGGLE_4_PIN                  FOUR_PIN_PORT ^= FOUR_PIN_MASK



// RGB Green LED
#define GREEN_LED_BIT                 1
#define GREEN_LED_MASK                (0x01 << GREEN_LED_BIT)
#define GREEN_LED_PORT                P2->OUT
#define GREEN_LED_DDR                 P2->DIR
#define SET_GREEN_LED_AS_AN_OUTPUT    GREEN_LED_DDR |= GREEN_LED_MASK
#define TURN_ON_GREEN_LED             GREEN_LED_PORT |= GREEN_LED_MASK
#define TURN_OFF_GREEN_LED            GREEN_LED_PORT &= ~GREEN_LED_MASK
#define TOGGLE_GREEN_LED              GREEN_LED_PORT ^= GREEN_LED_MASK


#endif

