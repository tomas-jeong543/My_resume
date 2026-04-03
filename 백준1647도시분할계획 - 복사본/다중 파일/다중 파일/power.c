double power(int x, int y)
{
	extern int my;
	double result = 1.0;
	int i;

	for (i = 0; i < y; i++)
		result = result * x;
	printf("main-my %d\n", my);
	return result;
}