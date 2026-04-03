#include<stdio.h>

void print_screen(int a[5][5]);
int brighten(int b[5][5]);

int main(void)
{
	int screen[5][5] = {
		{ 10,120,130,240,250 },
		{ 10,120,130,240,250 },
		{ 10,120,130,240,250 },
		{ 10,120,130,240,250 },
		{ 10,120,130,240,250 }
	};
	 
	 print_screen(screen);
	 screen[5][5] = brighten(screen);
	 print_screen(screen);

	 return 0;
}

void print_screen(int a[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%2d ", a[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

int brighten(int b[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			b[i][j] = b[i][j] + 10;
		
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			if (b[i][j] > 255)
				b[i][j] = 255;

	}
	return b[5][5];
}