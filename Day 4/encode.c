#include <stdio.h>
#include <stdlib.h>

char token;

int letters[26];
char name[255];
int pos = 0;

int total = 0;

int sector = 0;
int i = 0;

int mode = 1;
int succ = 1;

char max(){
	int m = 0;
	char k = 'a';
	for(i = 25; i>=0; i--){
		if(letters[i] >= m){
			m = letters[i];
			k = 'a' + i;
		}
	}
	letters[k - 'a'] = 0;
	return k;
}

void main(){
	for(i = 0; i < 26; i++){
		letters[i] = 0;
	}

	while((token = getchar()) != '$'){
		name[pos] = token;
		pos++;
		if(token >= '0' && token <= '9'){
			sector = (sector * 10) + token - '0';
		}
		if(token >= 'a' && token <= 'z' && mode == 1){
			letters[token - 'a']++;
		}
		if(token == '[')
			mode = 2;
		if(token >= 'a' && token <= 'z' && mode == 2){
			if(max() != token){
				succ = 2;
			}
		}
		if(token == '\n'){
			if(succ == 1){
				total += sector;
				printf(name);
			}
			sector = 0;
			for(i = 0; i < 26; i++){
				letters[i] = 0;
			}
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
