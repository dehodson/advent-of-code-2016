#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//God this code is messy. I am not proud of this!

int x = 0;
int y = 0;
int direction = 0;
int steps = 0;

int x2 = 0;
int y2 = 0;
int direction2 = 0;
int steps2 = 0;

char input[1024];

void parse(char* start, char* end, bool first);

void move(char* ptr, bool first){
	int i = first ? steps : steps2;
	for(; i > 0; i--){
		if(first){
			if(direction == 0)
				y++;
			if(direction == 1)
				x++;
			if(direction == 2)
				y--;
			if(direction == 3)
				x--;
			x2 = y2 = direction2 = steps2 = 0;
			printf("%d,%d\n", x, y);
			parse(&input[0], ptr - 3, false);
		}else{
			if(direction2 == 0)
				y2++;
			if(direction2 == 1)
				x2++;
			if(direction2 == 2)
				y2--;
			if(direction2 == 3)
				x2--;
			if(x2 == x && y2 == y){
				printf("%d\n", (abs(x) + abs(y)));
				exit(1);
			}
		}
	}
	steps = steps2 = 0;
}

void parse(char* start, char* end, bool first){
	while(*start != '\n' && start < end){
		if(*start == 'R')
			first ? direction++ : direction2++;
		if(*start == 'L')
			first ? direction-- : direction2--;
		if(first){
			if(direction > 3)
				direction = 0;
			if(direction < 0)
				direction = 3;
		}else{
			if(direction2 > 3)
				direction2 = 0;
			if(direction2 < 0)
				direction2 = 3;
		}
		if(*start >= '0' && *start <= '9')
			first ? (steps = (steps * 10) + *start - '0') : (steps2 = (steps2 * 10) + *start - '0');
		if(*start == ',')
			move(start, first);
		start++;
	}
	move(start, first);
}

int main(){
	fgets(input, 1024, stdin);

	parse(&input[0], &input[1023], true);

	return 0;
}
