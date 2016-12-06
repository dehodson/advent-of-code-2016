#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char token;
int  pop[8][26];
int  pos = 0;
int  i =0;
int  j = 0;

char min(){
	i = 0;
	int m = 26;
	char k = 'z';
	for(i = 0; i<26; i++){
		if(pop[pos][i] <= m){
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

	for(j = 0; j < 8; j++){
		pos = j;
		printf("%c", min());
	}
	printf("\n");

	return 0;
}
