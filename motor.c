/**************************************************************
* Class:  CSC-615
* Name:	  Mark Jovero	
* Student ID:	916691664
* Project:	Assignment 3- Get Your Motor Started
*
* File: motor.c
*
* Description: This file allows for control of motor.
*
**************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <wiringPi.h>
#include "motor.h"

/* Description: Prepares I2C, calls functions by WaveShare
 * Arguments: None
 * Return: void
 */
void motor_wiring_setup() {
	
    PCA9685_Init(0x40);
    PCA9685_SetPWMFreq(100);
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_5, 0);
    PCA9685_SetLevel(PCA_CHANNEL_3, 1);
    PCA9685_SetLevel(PCA_CHANNEL_4, 0);
    
}

/* Description: Runs the motor
 * Arguments:
 * 	speed: the speed the motor spins (0 <= speed >= 100)
 * 	direction: the direction, forward or reverse (0: forward, 1: reverse)
 * Return: void
 */
void motor_set_speed(int speed, int direction) {
    if (speed > 100)
	speed = 100;
    else if (speed < 0)
	speed = 0;
	
    if (direction > 1)
	direction = 1;
    else if (direction < 0)
	direction = 0;


    PCA9685_SetPWMFreq(100);
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_5, speed);
    
    if (direction == 0) { // forward
	PCA9685_SetLevel(PCA_CHANNEL_3, 0);
	PCA9685_SetLevel(PCA_CHANNEL_4, 1);
    } else { // backward
	PCA9685_SetLevel(PCA_CHANNEL_3, 1);
	PCA9685_SetLevel(PCA_CHANNEL_4, 0);
    }
}
