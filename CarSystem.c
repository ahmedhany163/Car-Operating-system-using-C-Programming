 /******************************************************************************
 *
 * File Name: CarSystem.c
 *
 * Description: Simulating a car operating system using C functionalities to understand car system flow
 *
 * Author: Ahmed Hany
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

unsigned short engine_temp=0, room_temp=20;
char traffic_color, speed=0, engine=0, ac_state=0, engine_cont_state=0;

void current_state(){
	printf(" \n");
	if(engine==1)
		printf("Engine is ON \n");
	else
		printf("Engine is OFF \n");

	printf("Speed = %d \n", speed);

	if(ac_state==1)
		printf("AC is ON \n");
	else
		printf("AC is OFF \n");

	printf("Room temperature is %d \n", room_temp);
	printf("Engine temperature is %d \n", engine_temp);

	if(engine_cont_state==1)
		printf("Engine temperature controller is ON \n");
	else
		printf("Engine temperature controller is OFF \n");

	printf("\n");
}

void vehicle_on(){
	while(1){
		printf("a. Turn off vehicle engine \n");
		printf("b. Set the traffic light color \n");
		printf("c. Set the room temperature \n");
		printf("d. Set engine temperature \n");
		char selection;
		scanf(" %c", &selection);
		switch(selection){
		case 'a':
		case 'A':
			speed =0;
			engine=0;
			ac_state=0;
			engine_cont_state=0;
			printf("Turning off completed! \n");
			return;

		case 'b':
		case 'B':
			printf("Select light color \n");
			printf("G. for 100km/h \n");
			printf("O. for 30km/h \n");
			printf("R. for 0km/h \n");
			scanf(" %c", &traffic_color);
			switch(traffic_color){
			case 'g':
			case 'G':
				speed = 100;
				printf("Speed set to 100km/h \n");
				break;
			case 'o':
			case 'O':
				speed = 30;
				printf("Speed set to 30km/h \n");

				ac_state=1;
				room_temp= ((room_temp*5/4)+1);

				engine_cont_state=1;
				engine_temp=((engine_temp*5/4)+1);

				break;
			case 'r':
			case 'R':
				speed = 0;
				printf("Speed set to 0km/h \n");
				break;
			default:
				printf("Error! \n");
				break;
			}
			current_state();
			break;

		case 'c':
		case 'C':
			printf("Set room temperature \n");
			scanf("%hu", &room_temp);

			if(room_temp<10 || room_temp>30){
				ac_state=1;
				room_temp=20;
			}
			else
				ac_state=0;

			current_state();
			break;

		case 'd':
		case 'D':
			printf("Enter engine temperature \n");
			scanf("%hu", &engine_temp);

			if(engine_temp<100 || engine_temp>150){
				engine_cont_state=1;
				engine_temp=125;
			}
			else
				engine_cont_state=0;

			current_state();
			break;

		default:
			printf("Error! \n");
			break;
		}
	}
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	current_state();
	printf("\n \n");
	char state;

	while(1){
		printf("a. Turn on vehicle engine \n");
		printf("b. Turn off vehicle engine \n");
		printf("c. Quit the system \n");
		scanf(" %c", &state);
		switch(state){
		case 'a':
		case 'A':
			engine=1;
			engine_temp = 95;
			vehicle_on();
			break;
		case 'b':
		case 'B':
			speed =0;
			printf("Turning off completed \n");
			break;
		case 'c':
		case 'C':
			printf("Good bye! \n");
			return 1;
		default:
			printf("Error! \n");
			break;
		}

	}

}
