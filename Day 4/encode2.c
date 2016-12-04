#include <stdio.h>
#include <stdlib.h>

char token;

int letters[26];

int total = 0;

int sector = 0;
int i = 0;

int mode = 1;
int succ = 1;

int pos = 0;
char name[255];
char* ptr;

char shift(int num, char l){
	if(l == '-'){
		return ' ';
	}
	while(num > 0){
		l++;
		num--;
		if(l > 'z')
			l = 'a';
	}
	return l;
}

void main(){
	for(i = 0; i < 26; i++){
		letters[i] = 0;
	}

	while((token = getchar()) != '$'){
		if(token >= '0' && token <= '9'){
			sector = (sector * 10) + token - '0';
		}
		if(token >= 'a' && token <= 'z' && mode == 1){
			name[pos] = token;
			pos++;
		}
		if(token == '\n'){
			if(succ == 1){
				total += sector;
			}
			printf("%d ", sector);
			for(i = 0; i < pos; i++){
				printf("%c", shift(sector,name[i]));
			}
			printf("\n");
			sector = 0;
			for(i = 0; i < 255; i++){
				name[i] = 0;
			}
			pos = 0;
			mode = 1;
			succ = 1;
		}
	}

	printf("%d\n", total);
}
