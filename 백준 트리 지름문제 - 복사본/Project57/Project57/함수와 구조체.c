#include<stdio.h>
#include<string.h>

union example {
	int i;
	char c;
};

int main(void)
{
	union example v;
	v.c = 'A';
	printf("%d %c\n", v.i, v.c);
	v.i = 30;
	printf("%d %c\n", v.i, v.c);
	return 0;
}
