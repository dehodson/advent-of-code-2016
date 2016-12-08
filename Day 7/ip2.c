#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char token;

char outside[255];
char  inside[255];
char* out = &outside[0];
char* in  = &inside[0];

int mode = 0;
int total = 0;

bool check(){
	int x = 0;
	int y = 0;
	while(outside[x + 2]){
		if(outside[x] == outside[x + 2] && outside[x] != outside[x + 1]){
			while(inside[y + 2]){
				if(outside[x] == inside[y + 1] &&
				   outside[x + 1] == inside[y] &&
				   inside[y] != inside[y + 1]){
					return true;
				}
				y++;
			}
		}
		x++;
	}
	return false;
}

int main(){
	FILE *input = fopen("input", "r");

	while((token = (char)fgetc(input)) != EOF){
		if(token >= 'a' && token <= 'z'){
			if(mode == 0){
				*out = token;
				out++;
			}
			if(mode == 1){
				*in  = token;
				in++;
			}
		}
		if(token == '['){
			// *out = ' ';
			// out++;
			mode = 1;
		}
		if(token == ']'){
			// *in  = ' ';
			// in++;
			mode = 0;
		}
		if(token == '\n'){
			if(check())
				total++;
			out = &outside[0];
			in  = &inside[0];
			mode = 0;
		}
	}

	printf("%d\n", total);

	return 0;
}
