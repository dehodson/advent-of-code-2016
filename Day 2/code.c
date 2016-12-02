#include <stdio.h>
#include <stdlib.h>

int x = 1;
int y = 1;

char pad[3][3] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
};

char token;
char sequence[255];
int  pos = 0;

void main(){
	while((token = getchar()) != '$'){
		if(token == 'U' && y > 0)
			y--;
		if(token == 'D' && y < 2)
			y++;
		if(token == 'L' && x > 0)
			x--;
		if(token == 'R' && x < 2)
			x++;
		if(token == '\n'){
			sequence[pos] = pad[y][x];
			pos++;
		}
	}
	sequence[pos] = pad[y][x];
	pos++;

	printf("%s\n", sequence);
}
