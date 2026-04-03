//기초 계산 함수
int Add(int x, int y)
{
	return x + y;
}

int Subtract(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Divide(int x, int y)
{
	if (x >= 0) {
		return x / y;
	}
	else {
		x *= -1;
		return -1 * (x / y);
	}
	
}

