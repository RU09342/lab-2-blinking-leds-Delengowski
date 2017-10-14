// Author: Matt Delengowski
// Lab: 2
// Section: Multiple Blink
// Device: FR2311

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P2DIR |= BIT0;                          // Set P2.0 to output direction

        for(;;) {
            volatile unsigned int i;            // volatile to prevent optimization

            P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR
            P2OUT ^= BIT0;                      // Toggle P2.0 using exclusive-OR

            i = 10000;                          // SW Delay
            do i--;
            while(i != 0);

            P2OUT ^= BIT0;
            i = 10000;
            do i--;
            while(i != 0);
        }
}
