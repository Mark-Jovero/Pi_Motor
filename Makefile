
run: assignment3.c
	gcc -c motor.c button.c DEV_Config.c PCA9685.c
	gcc -I -g motor.o button.o DEV_Config.o PCA9685.o -Wall -o assignment3 assignment3.c -l wiringPi -lm
	sudo ./assignment3
clean:	
	rm assignment3
	rm *.o
