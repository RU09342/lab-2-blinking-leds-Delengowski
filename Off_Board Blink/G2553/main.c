// Author: Matt Delengowski
// Lab: 2
// Section: Off Board Blink
// Device: G2553
#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

     P1DIR |= BIT0;                          // Set P1.0 to output direction
     P1DIR |= BIT6;                          // Set P9.0 to output direction

            for(;;) {
                volatile unsigned int i;            // volatile to prevent optimization

                P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
                P1OUT ^= BIT6;                      // Toggle P1.0 using exclusive-OR

                i = 10000;                          // SW Delay
                do i--;
                while(i != 0);

                P1OUT ^= BIT6;
                i = 10000;
                do i--;
                while(i != 0);
            }
}
