int Add(int num1, int num2) 
{
	return num1 + num2;
}

int Subtract(int num1, int num2)
{
	return num1 - num2;
}

int Mul(int num1, int num2)
{
	return num1 * num2;
}

int Divide_Plus(int num1, int num2)
{
	return num1 / num2;
}

int Divide_Minus(int num1, int num2)
{
	int leftover = -((-1 * num1) / num2);

	return leftover;
}