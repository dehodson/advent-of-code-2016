#include <stdio.h>
#include <stdlib.h>

char token;

int nums[3][3];
int current = 0;
int space = 1;

int total = 0;

void main(){
	while((token = getchar()) != '$'){
		if(token >= '0' && token <= '9'){
			space = 0;
			nums[current] = (nums[current] * 10) + token - '0';
		}
		if(space == 0 && token == ' '){
			space = 1; current++;
		}
		if(token == '\n'){
			if( nums[0] + nums[1] > nums[2] && 
				nums[1] + nums[2] > nums[0] &&
				nums[2] + nums[0] > nums[1])
				total++;
			nums[0] = 0;
			nums[1] = 0;
			nums[2] = 0;
			current = 0;
			space = 1;
		}
	}

	printf("%d\n", total);
}
