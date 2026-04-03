#include<stdio.h>
extern int  Getnum(void);
extern void Increasment(void);

int main(void) {

	printf("num: %d \n", Getnum());
	Increasment();
	printf("num: %d \n", Getnum());
	Increasment();
	printf("num: %d \n", Getnum());
	return 0;
}