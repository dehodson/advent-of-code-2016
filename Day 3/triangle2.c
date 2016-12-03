#include <stdio.h>
#include <stdlib.h>

char token;

int nums[3][3];
int current = 0;
int currant = 0;
int space = 1;

int total = 0;
int i = 0;

void main(){
	while((token = getchar()) != '$'){
		if(token >= '0' && token <= '9'){
			space = 0;
			nums[current][currant] = (nums[current][currant] * 10) + token - '0';
		}
		if(space == 0 && token == ' '){
			space = 1; current++;
		}
		if(token == '\n'){
			currant++;
			if(currant == 3){
				currant = 0;
				for(i = 0; i < 3; i++){
					if( nums[i][0] + nums[i][1] > nums[i][2] && 
						nums[i][1] + nums[i][2] > nums[i][0] &&
						nums[i][2] + nums[i][0] > nums[i][1])
						total++;
					nums[i][0] = 0;
					nums[i][1] = 0;
					nums[i][2] = 0;
				}
			}
			current = 0;
			space = 1;
		}
	}

	printf("%d\n", total);
}
