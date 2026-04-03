#include<stdio.h>
#include"func.h"
#include"simplecalfunc.h"

//오름차순 정렬 단 첫번째 변수는 제외
void Sortedupper(int * arr, int size)
{
	int tmp;

	for (int i = 1; i < size; i++) {
		for (int j = i + i; j < size; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}


}

// 연산자의 종류의 개수를 연산자 정보를 저장하는 배열의 정보를 이용해 구해 반환하는 함수
int Findcalsymbolnum(int * calinfo)
{
	int count = 0;

	for (int i = 0; i < 4; i++) {
		if (*(calinfo + i) > 0)
			count += 1;
	}

	return count;
}


// idx값을 이용해 그에 맞는 계산을 하고 반환하는 함수
int calculator(int idx, int num1, int num2)
{
	

	switch (idx) {
		case 0:
			return Add(num1, num2);
		case 1:
			return Subtract(num1, num2);
		case 2:
			return Mul(num1, num2);
		case 3:
			return Divide(num1, num2);

	}
}

//최댓값을 찾는 함수 원리는 간단하다 연산자의 종류와 개수에 따른 모든 케이스에 대해 연산이 최대가 되는
//순서를 순서 저장 배열에 입력하고 이 순서정보와 연산 횟수 정보를 이용해 그 순서에 따라 연산하고 그 값을 반환한다.
int FindMax(int* numinfo, int* calinfo, int* calsequence, int size, int symbol_num)
{
	//첫 숫자 초기화
	int num = *(numinfo + 0);
	// 순서정보에 접근하기 위한 변수
	int sequenceidx = 0;
	
	// 연산자 종류의 개수에 따른 1차 분류 1,2,3,4개의 연산자가 있을 때로 나뉜다.
	switch (symbol_num) {
	 case 1: {
		
		 //연산자가 1개면 그냥 그연산자 순서 정보의 첫 번째에 그 값을 넣고 그냥 연산 횟수 만큼 그 연산 시행
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
		
		 //총 6가지 경우에 대해 가장 연산 결과가 최대가 되게 연산 순서를 저장하고 그 순서와 횟수 정보를 이용해 연산을 진행하고
		 // 연산값을 반환한다.
		 if (calinfo[0] > 0 && calinfo[1] > 0) {
			
			 Sortedupper(numinfo, size + 1);
			 
			 calsequence[0] = 1;
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
		 else  if (calinfo[0] > 0 && calinfo[2] > 0) {
			 calsequence[0] = 0;
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
		 else  if (calinfo[0] > 0 && calinfo[3] > 0) {
			 calsequence[0] = 3;
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
		 else  if (calinfo[1] > 0 && calinfo[2] > 0) {
			 calsequence[0] = 2;
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
		 else  if (calinfo[1] > 0 && calinfo[3] > 0) {
			 calsequence[0] = 1;
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
		 else  if (calinfo[2] > 0 && calinfo[3] > 0) {
			 Sortedupper(numinfo, size + 1);
			 calsequence[0] = 3;
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
	 }
	 case 3: {
		 // 총 4가지 경우에 대해 가장 연산 결과가 최대가 되게 연산 순서를 저장하고 그 순서와 횟수 정보를
		 //  이용해 연산을 진행하고
		// 연산값을 반환한다.
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
			 calsequence[0] = 3;
			 calsequence[1] = 0;
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
			 calsequence[0] = 1;
			 calsequence[1] = 3;
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
		 else if (calinfo[3] == 0) {

			 calsequence[0] = 0;
			 calsequence[1] = 2;
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

	 }
	 case 4: {
		//모든 연산자가 있는 경우에 대한 연산 순서 지정
		 calsequence[0] = 1;
		 calsequence[1] = 3;
		 calsequence[2] = 0;
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

