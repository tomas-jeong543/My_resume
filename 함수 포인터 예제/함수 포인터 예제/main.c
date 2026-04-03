#include<stdio.h>
#include"calcul.h"
#include"InterFace.h"

int main(void) {

	int opt = 0;
	double n1, n2;
	void(*cal[6])(double, double);

	cal[0] = Add;
	cal[1] = Subtract;
	cal[2] = Mul;
	cal[3] = Divide;
	cal[4] = Qution;
	cal[5] = Remainder;

	while (opt != 7) {
		
		Menu();
		opt = GetOption();

		if (opt == 7) {
			Close();
			break;
		}
		n1 = GetNum();
		n2 = GetNum();
		
		puts("");
	
		cal[opt - 1](n1, n2);
	}
	return 0;
}