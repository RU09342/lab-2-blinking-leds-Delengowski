// Author: Matt Delengowski
// Lab: 2
// Section: Multiple Blink
// Device: F5529

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P4DIR |= BIT7;                          // Set P9.0 to output direction

    P1OUT &= ~BIT0;
    P4OUT &= ~BIT7;

        for(;;) {
            volatile unsigned int i;            // volatile to prevent optimization

            P1OUT ^= BIT0; //Toggle LED P1.0
            P4OUT ^= BIT7;                      // Toggle P4.7 using exclusive-OR
            for(i=10000; i>0; i--);     // delay

            P4OUT ^= BIT7;
            for(i=10000; i>0; i--);     // delay
        }
}
