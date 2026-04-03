#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	char board[3][3];
	int x, y, k, i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			board[i][j] = ' ';
	for (k = 0; k < 9; k++)
	{
		printf("0  I 1 I 2\n");
		for (i = 0; i < 3; i++)
		{
			printf("---I---I---\n");
			printf("%c  I %c I %c\n", board[i][0], board[i][1], board[i][2]);
		}
		printf("---I---I---\n");

		printf("(x,y)ÁÂÇ¥:");
		scanf("%d %d", &x, &y);

		if (k % 2 == 0)
			board[x][y] = 'X';
		else
			board[x][y] = 'O';

	}
	return 0;
}