#include<stdio.h>
//자릿수 정보를 얻어 반환하는 함수
int digits(int x)
{
	int divider = 1, digitnum = 0;

	while (x / divider > 0) {
		digitnum += 1;
		divider *= 10;
	}

	return digitnum;
}
//자릿수의 합을 구해 반환하는 함수
int digitsum(int x)
{
	int divider = 10, digitsum = 0;

	while (x > 0) {
		digitsum += (x % divider) / (divider / 10);
		x -= x % divider;
		divider *= 10;
	}

	return digitsum;
}
//d(n)값을 계산해 반환하는 함수
int FindDn(int x)
{
	return x + digitsum(x);
}

//자릿수 정보를 통해  n의 자리 숫자는 그 숫자 - 9 * n부터 그 숫자의 생성자가 될 수 있다는 점을 이용해 각 경우에 대한 연산
//횟수를 최소화 한다.
int FindMinDN(int x, int digitnum)
{
	

	switch (digitnum) {
	case 1: {
		for (int i = x - 9; i < x; i++) {
			if (FindDn(i) == x)
				return i;
		}
		break;
	}
	case 2: {
		for (int i = x - 18; i < x; i++) {
			if (FindDn(i) == x)
				return i;
		}
		break;
	}
	case 3: {
		for (int i = x - 27; i < x; i++) {
			if (FindDn(i) == x)
				return i;
		}
		break;
	}
	case 4: {
		for (int i = x - 36; i < x; i++) {
			if (FindDn(i) == x)
				return i;
		}
		break;
	}

	}

	return 0;
}