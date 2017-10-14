// Author: Matt Delengowski
// Lab: 2
// Section: Button Blink
// Device: FR5994

#include <msp430.h>

#define Button1Pressed !(BIT6 & P5IN)       //Button P5.6 Pressed
#define LED1Toggle     P1OUT ^= BIT0;       //Toggle P1.0 LED On/Off

void ButtonSettings();
void LEDSettings();

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    ButtonSettings();
    LEDSettings();

    volatile unsigned int i;                // volatile to prevent optimization
    volatile unsigned int Speed_Sel = 0;

   for(;;)
       {
           switch(Speed_Sel)
               {
                 case 0:
                     {
                         if (Button1Pressed) break;
                         i = 5000;
                         do
                             {
                              i--;
                              if (Button1Pressed)
                                  {
                                      Speed_Sel++;
                                      _delay_cycles(500000);
                                      break;
                                  }
                             }
                         while(i !=0);
                         LED1Toggle;
                         break;
                     }
                 case 1:
                     {
                         if (Button1Pressed) break;
                         i = 10000;
                         do
                             {
                              i--;
                              if (Button1Pressed)
                                  {
                                      Speed_Sel++;
                                      _delay_cycles(500000);
                                      break;
                                  }
                             }
                         while(i !=0);
                         LED1Toggle;
                         break;
                     }
                 case 2:
                     {
                         if (Button1Pressed) break;
                         i = 20000;
                         do
                             {
                              i--;
                              if (Button1Pressed)
                                  {
                                      Speed_Sel++;
                                      _delay_cycles(500000);
                                      break;
                                  }
                             }
                         while(i !=0);
                         LED1Toggle;
                         break;
                     }
                 case 3:
                     {
                         if (Button1Pressed) break;
                         Speed_Sel = 0;
                         break;
                     }
               }
       }
}

void ButtonSettings()
{
    P5DIR &= ~BIT6;                         // Set P5.6 to input
    P5REN |= BIT6;                          // Enable Pull Up Resistor for pin5.6
    P5OUT |= BIT6;                          //SPECIFIED AS A PULLUP FOR P5.6
}

void LEDSettings()
{
    P1DIR |= BIT0;                          // Set P1.0 to output direction (Red LED, Right one)
    P1OUT &= ~BIT0;                         //SET LED1 OFF
}
