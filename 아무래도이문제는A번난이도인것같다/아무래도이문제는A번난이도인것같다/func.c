
int DetallDivisors(int A,int B)
{
	int c;

	for (int i = 1; i < A; i++) {
		
		c = A / i;
		if (A % i == 0 && c + i == B)
			return 0;
	}

	return -1;
}