# Button Blink Lab 2
## Goals
To blink an LED when you press a botton.
## Code
To code this requires some extra compared to the other sections. The extra is merely settings the registers for the pin of the button. For example on the FR6989, you must set P1.1 direction register to zero this is done using by using the NAND function, enable the resistor for the pin in question (by setting it one with OR function), and lastly designate that resistor as a pull up (because the buttons are active high). After you have configured the P1.1 settings you can poll using a forever loop with a nested if else statement to toggle the LED on and off. Some like below

  for(;;)

  {

   if (!(BIT1 & P1IN)) //it is the negation because the switches are active high, we want a logical 1 when the button is giving a 0. 
  
     P1OUT |= BIT0; //turns LED ON
    
   else
  
     P1OUT &= BIT0; //turns LED OFF
    
  }

The extra portion of lab 2 was done for this section. The button based speed control was implemented. This was done using polling and a nested switch statement, whose case was some variable that was incremented every time the button was pressed. The speed of the LEDs was done in the same fashion of the other sections, using a do-while loop. Each case had a longer do while loop, causing the LED to blink slower. Additionally, in each case is a hefty delay cycle to account for debouncing. 

## original
# Button Blink
Now that you have looked at blinking the LED from some built in delay, but what if we wanted to control the state of the LED by a button? You may think "Why would I need a Microcontroller to perform the job of a switch?". And that is where you come in. The bare minimum for this part of the lab is to essentially replicate a switch with your development board.

# YOU NEED TO CREATE THE FOLLOWING FOLDERS
* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989

## README
Remember to replace this README with your README once you are ready to submit. I would recommend either making a copy of this file or taking a screen shot. There might be a copy of all of these README's in a folder on the top level depending on the exercise.

## Extra Work
What can we do to make this a little bit more worthy of needing a microcontroller.

### Button Based Speed Control
Much like the UART controlled speed, what if you could cycle between speeds based on a button press? The speed could progress through a cycle of "Off-Slow-Medium-Fast" looping back when you hit the end.

### Color Change
What if upon a button press, the LED which was blinking changed. Some of the development boards contain two LEDs, so you could swap between a Red and a Green LED.
