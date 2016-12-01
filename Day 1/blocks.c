#include <stdio.h>
#include <stdlib.h>

int x = 0;
int y = 0;
int direction = 0;
int steps = 0;

char token;

void move(){
	if(direction == 0)
		y += steps;
	if(direction == 1)
		x += steps;
	if(direction == 2)
		y -= steps;
	if(direction == 3)
		x -= steps;
	steps = 0;
}

void main(){
	while((token = getchar()) != '\n'){
		if(token == 'R')
			direction++;
		if(token == 'L')
			direction--;
		if(direction > 3)
			direction = 0;
		if(direction < 0)
			direction = 3;
		if(token >= '0' && token <= '9')
			steps = (steps * 10) + token - '0';
		if(token == ',')
			move();
	}
	move();

	printf("%d\n", (abs(x) + abs(y)));
}
