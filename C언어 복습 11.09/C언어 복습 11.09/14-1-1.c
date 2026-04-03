/*#include<stdio.h>

int SquareByValue(int num);
void SquareByReference(int* num);

int main(void) {
	int num = 3;
	int numsquare;
	printf("mum = %d\n", num);
	
	numsquare = SquareByValue(num);
	printf("mumÀÇ Á¦°ö = %d\n", numsquare);
	
	num = 5;
	printf("mum = %d\n", num);

	SquareByReference(&num);
	printf("mumÀÇ Á¦°ö = %d\n", num);
	return 0;
}

int SquareByValue(int num) {
	int numsquare = num * num;
	return numsquare;
}

void SquareByReference(int* num) {
	int temp;

	temp = *(num) * *(num);
	*num = temp;
}*/