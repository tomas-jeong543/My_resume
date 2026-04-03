#include<stdio.h>

void Make2num(int num, int len);


int main(void) {
	
	int num;
	int len = 1;
	int temp;
	printf("10진수 정수 입력:");
	scanf_s("%d", &num);
	temp = num;
	while (temp >= 2) {
		temp /= 2;
		len++;
	}

	Make2num(num, len);

	return 0;
}

void Make2num(int num, int len) {
		
	int multiplier = 1;
	int count = len;
	
	for (int i = 0; i < len; i++) {
		
		
		multiplier = 1;

		for (int j = 0; j < count - 1; j++) { 
			multiplier *= 2;
		}
		
		if (multiplier > num) {
			printf("0");

		}
		else {
			printf("1");
			num -= multiplier;
		}
		count -= 1;
	}
	

}
