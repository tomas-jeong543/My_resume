#include<stdio.h>

void display(int image[8][16])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (image[i][j] == 0)
				printf("*");
			else
				printf("_");
		}
		printf("\n");
	}
}

void inverse(int image[8][16])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (image[i][j] == 0)
				image[i][j] = 1;
			else
				image[i][j] = 0;
		}
		
	}
}

int main(void)
{
	int image[8][16] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{ 1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1},
		{ 1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1},
		{ 1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1},
		{ 1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	printf("변환전 이미지\n");
	display(image);
	inverse(image);
	printf("변환후 이미지\n");
	display(image);

	return 0;
}