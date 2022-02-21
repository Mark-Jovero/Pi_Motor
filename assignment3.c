//
// Created by Mark on 3/18/2021.
//
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "motor.h"
#include "button.h"


int main(int argc, char *argv[]) {
    int speed;
    
    wiringPiSetup();
    motor_wiring_setup();
    button_wiring_setup(15,16);
    
    printf("Press button to run motor.\n");
    while (!button_pressed()) {
        
    }
    
    speed = 100;
    printf("Running motor at %d\n", speed);
    motor_set_speed(speed, 0);
    delay(2000);
    
    while (speed > 15) {
        speed--;
        delay(75);
        printf("Slowing down... %d\n", speed);
        motor_set_speed(speed, 0);
    }
    
    printf("Stopping motor.");
    motor_set_speed(0, 1);
    delay(1000);
    
    while (speed < 100) {
        speed++;
        delay(75);
        printf("Speeding up in reverse... %d\n", speed);
        motor_set_speed(speed, 1);
    }
    
    delay(1000);
    motor_set_speed(0, 1);


    return 0;
}
