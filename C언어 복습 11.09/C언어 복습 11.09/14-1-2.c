#include<stdio.h>

void Swap3(int* param1, int* param2, int* param3);

int main(void) {

	int num1 = 1, num2 = 2, num3 = 3;
	
	printf("num1: %d num2: %d num3: %d\n", num1, num2, num3);
	
	Swap3(&num1, &num2, &num3);
	
	printf("Swap ÈÄ");
	printf("num1: %d num2: %d num3: %d\n", num1, num2, num3);
	return 0;
}

void Swap3(int* param1, int* param2, int* param3) {
	
	int temp = 0;
	temp = *param1;
	*param1 = *param2;
	*param2 = *param3;
	*param3 = temp;

}
