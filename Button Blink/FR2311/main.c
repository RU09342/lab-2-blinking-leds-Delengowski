// Author: Matt Delengowski
// Lab: 2
// Section: Button Blink
// Device: FR2311

#include <msp430.h>

#define Button1Pressed !(BIT1 & P1IN)       //Button P1.1 Pressed
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
    P1DIR &= ~BIT1;                         // Set P1.1 to input
    P1REN |= BIT1;                          // Enable Pull Up Resistor for pin1
    P1OUT |= BIT1;                          //SPECIFIED AS A PULLUP FOR P1.1
}

void LEDSettings()
{
    P1DIR |= BIT0;                          // Set P1.0 to output direction (Red LED, Right one)
    P1OUT &= ~BIT0;                         //SET LED1 OFF
}
