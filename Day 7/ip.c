#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char token;
char abba[4] = {' ', ' ', ' ', ' '};
int  mode = 0;
int  num  = 0;
int  succ = 0;
int  fail = 0;

int total = 0;

void insert(char new){
	int i;
	for(i = 0; i<3; i++){
		abba[i] = abba[i + 1];
	}
	abba[3] = new;
}

bool check(){
	return (abba[0] == abba[3] && abba[1] == abba[2]
		&&  abba[0] != abba[1] && abba[2] != abba[3]);
}

int main(){
	FILE *input = fopen("input", "r");

	while((token = (char)fgetc(input)) != EOF){
		if(token >= 'a' && token <= 'z'){
			insert(token);
			num++;
			if(num >= 4){
				if(check() && mode == 0)
					succ = 1;
				if(check() && mode == 1)
					fail = 1;
			}
		}
		if(token == '['){
			mode = 1;
			num  = 0;
		}
		if(token == ']'){
			mode = 0;
			num  = 0;
		}
		if(token == '\n'){
			if(succ == 1 && fail == 0){
				total++;
			}
			mode = 0;
			num  = 0;
			succ = 0;
			fail = 0;
		}
	}

	printf("%d\n", total);

	return 0;
}
