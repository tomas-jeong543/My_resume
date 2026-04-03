#include<stdio.h>
#include<ctype.h>

int count_word(char* s);

int main(void)
{
	int wc = count_word("the c book a b");
	printf("단어의 개수 %d\n", wc);

	return 0;
}

int count_word(char* s)
{
	int i, wc = 0;
	int waiting = 1;

	for (i = 0; s[i] != NULL; i++)
	{
		if (isalpha(s[i]))
		{
			if (waiting)
			{
				wc++;
				waiting = 0;
			}
		}
		else
			waiting = 1;
	}
	return wc;
}