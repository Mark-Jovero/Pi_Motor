/**************************************************************
* Class:  CSC-615
* Name:	  Mark Jovero	
* Student ID:	916691664
* Project:	Assignment 3- Get Your Motor Started
*
* File: button.c
*
* Description: This file allows detection of button press.
*
**************************************************************/

#include "button.h"
#include <wiringPi.h>

int IN;
int OUT;

/* Description:
 *      Assigns button's pins
 * Args:
 *      pin_output: The wiringPi pin that provides current
 *      pint_input: The wiringPi pin that reads current 
 * Return:
 *      void
 */
void button_wiring_setup(int pin_output, int pin_input) {
    IN = pin_input;
    OUT = pin_output;
    pinMode(OUT, OUTPUT);
    pinMode(IN, INPUT);
    digitalWrite(OUT, LOW);
}

/* Description: Reads the pin_input value
 * Arguments: None
 * Return:
 *      0: Button not pressed
 *      1: Button pressed
 */
int button_pressed() {
    return !digitalRead(IN);
}
