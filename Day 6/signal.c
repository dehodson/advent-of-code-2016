#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char token;
int  pop[8][26];
int  pos = 0;
int  i =0;

char max(){
	int m = 0;
	char k = 'a';
	for(i = 25; i>=0; i--){
		if(pop[pos][i] >= m){
			m = pop[pos][i];
			k = 'a' + i;
		}
	}
	return k;
}

int main(){
	FILE *input = fopen("input", "r");

	while((token = (char)fgetc(input)) != EOF){
		if(token >= 'a' && token <= 'z'){
			pop[pos][token - 'a']++;
			pos++;
		}
		if(token == '\n'){
			pos = 0;
		}
	}

	int i;
	for(i = 0; i < 8; i++){
		pos = i;
		printf("%c", max());
	}
	printf("\n");

	return 0;
}
