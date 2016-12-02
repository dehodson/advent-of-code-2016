#include <stdio.h>
#include <stdlib.h>

int x = 1;
int y = 1;

char pad[5][5] = {
	{' ', ' ', '1', ' ', ' '},
	{' ', '2', '3', '4', ' '},
	{'5', '6', '7', '8', '9'},
	{' ', 'A', 'B', 'C', ' '},
	{' ', ' ', 'D', ' ', ' '}
};

char token;
char sequence[255];
int  pos = 0;

char charAt(int x, int y){
	return pad[y][x];
}

void main(){
	while((token = getchar()) != '$'){
		if(token == 'U' && y > 0 && charAt(x, y-1) != ' ')
			y--;
		if(token == 'D' && y < 4 && charAt(x, y+1) != ' ')
			y++;
		if(token == 'L' && x > 0 && charAt(x-1, y) != ' ')
			x--;
		if(token == 'R' && x < 4 && charAt(x+1, y) != ' ')
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
