#include<stdio.h>
#include"func.h"
#include"simplecalfunc.h"

// FindMax함수와 원리가 같다.
int FindMin(int* numinfo, int* calinfo, int* calsequence, int size, int symbol_num)
{
	int num = *(numinfo + 0);
	int idx = -1;
	int sequenceidx = 0;


	switch (symbol_num) {
	case 1: {

		for (int i = 0; i < 4; i++) {
			if (calinfo[i] > 0) {
				calsequence[0] = i;
			}
		}
		for (int i = 1; i < size + 1; i++) {
			num = calculator(calsequence[0], num, *(numinfo + i));
		}
		return num;
	}
	case 2: {

		if (calinfo[0] > 0 && calinfo[1] > 0) {

			Sortedupper(numinfo, size + 1);

			calsequence[0] = 0;
			calsequence[1] = 1;

			for (int i = 1; i < size + 1; i++) {

				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}
			}

			return num;
		}
		else  if (calinfo[0] > 0 && calinfo[2] > 0) {
			calsequence[0] = 2;
			calsequence[1] = 0;


			for (int i = 1; i < size + 1; i++) {


				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}

			}

			return num;
		}
		else  if (calinfo[0] > 0 && calinfo[3] > 0) {
			calsequence[0] = 0;
			calsequence[1] = 3;

			for (int i = 1; i < size + 1; i++) {

				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}
			}
			return num;
		}
		else  if (calinfo[1] > 0 && calinfo[2] > 0) {
			calsequence[0] = 1;
			calsequence[1] = 2;

			for (int i = 1; i < size + 1; i++) {

				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}
			}
			return num;
		}
		else  if (calinfo[1] > 0 && calinfo[3] > 0) {
			calsequence[0] = 3;
			calsequence[1] = 1;

			for (int i = 1; i < size + 1; i++) {

				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}
			}
			return num;
		}
		else  if (calinfo[2] > 0 && calinfo[3] > 0) {
			
			Sortedupper(numinfo, size + 1);
			calsequence[0] = 2;
			calsequence[1] = 3;

			for (int i = 1; i < size + 1; i++) {

				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}
			}
			return num;
		}
	}
	case 3: {

		if (calinfo[0] == 0) {
			calsequence[0] = 1;
			calsequence[1] = 3;
			calsequence[2] = 2;

			for (int i = 1; i < size + 1; i++) {

				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}
			}
			return num;
		}
		else if (calinfo[1] == 0) {
			calsequence[0] = 0;
			calsequence[1] = 3;
			calsequence[2] = 2;

			for (int i = 1; i < size + 1; i++) {

				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}
			}
			return num;
		}
		else if (calinfo[2] == 0) {
			calsequence[0] = 0;
			calsequence[1] = 3;
			calsequence[2] = 1;

			for (int i = 1; i < size + 1; i++) {

				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}
			}
			return num;
		}
		else if (calinfo[3] == 0) {

			calsequence[0] = 1;
			calsequence[1] = 2;
			calsequence[2] = 0;

			for (int i = 1; i < size + 1; i++) {

				if (calinfo[calsequence[sequenceidx]] > 0) {
					num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
					calinfo[calsequence[sequenceidx]] -= 1;
					if (calinfo[calsequence[sequenceidx]] == 0)
						sequenceidx += 1;
				}
			}
			return num;
		}

	}
	case 4: {

		calsequence[0] = 0;
		calsequence[1] = 3;
		calsequence[2] = 1;
		calsequence[3] = 2;

		for (int i = 1; i < size + 1; i++) {

			if (calinfo[calsequence[sequenceidx]] > 0) {
				num = calculator(calsequence[sequenceidx], num, *(numinfo + i));
				calinfo[calsequence[sequenceidx]] -= 1;
				if (calinfo[calsequence[sequenceidx]] == 0)
					sequenceidx += 1;
			}
		}
		return num;

	}
	}


}