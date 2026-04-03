#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void printOptions()
{
	printf("1--¼·¾¾¿Âµµ¿¡¼­ È­¾¾¿Âµµ·Î º¯È¯\n");
	printf("2--È­¾¾¿Âµµ¿¡¼­ ¼·¾¾¿Âµµ·Î º¯È¯\n");
	printf("3--Á¾·á\n");
}

double C2F(double c_temp)
{
	return 9.0 / 5.0 * c_temp + 32;
}

double F2C(double f_temp)
{
	return (f_temp - 32.0) * 5.0 / 9.0;
}

int main(void)
{
	int choice;
	double temp;
	while (1) {
		printOptions();
		printf("¸Þ´º¿¡¼­ ¼±ÅÃÇÏ¼¼¿ä.");
		scanf("%d", &choice);
		if (choice == 3)break;
		else if (choice == 1)
		{
			printf("¼·¾¾¿Âµµ:");
			scanf("%lf", &temp);
			printf("È­¾¾¿Âµµ: %lf\n", C2F(temp));
		}
		else if (choice == 2) {
			printf("È­¾¾¿Âµµ:");
			scanf("%lf", &temp);
			printf("¼·¾¾¿Âµµ: %lf\n", F2C(temp));
		}
	}
	return 0;
}