#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void RemoveLineBuf() {

	while (getchar() != '\n');
}

int main(void) {
	
	int* numarr = (int *)malloc(sizeof(int) * 5);
	if (numarr == NULL) {
		return -1;
	}
	int num = 0;
	int arridx = 0;


	do {

		printf("숫자을 입력하시오: (종료를 원하면 -1을 누르시오)");
		scanf_s("%d", &num);
		RemoveLineBuf();

		numarr[arridx] = num;
		arridx += 1;

		printf("num: %d\n", numarr[arridx]);
		if ((arridx - 5) % 3 == 0) {
			
			if (numarr == NULL) {
				return -1;
			}

			numarr = (int*)realloc(numarr, sizeof(int) * 3);
		}


	} while (num != -1);

	for (int i = 0; i < arridx; i++)
		printf("%d ", numarr[arridx]);

	printf("\n");

	return 0;
}