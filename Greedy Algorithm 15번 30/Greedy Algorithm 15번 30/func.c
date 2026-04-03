#include<stdio.h>
#include<math.h>
//자릿수 찾는 함수
int FindLen(int num)
{
	//길이 0 초기화 나누는 수 1로 초기화
	int len = 0;
	int divider = 1;
	//divider로 나눈 몫이 0이 아니면 자릿수 1증가하고 divider값은 곱하기 10이된다
	while (num / divider > 0) {
		len += 1;
		divider *= 10;
	}

	return len;
}

//자릿수 정보를 바탕으로 자릿수를 포인터가 가르키는 메모리에 저장하는 함수
void FinddigitsInfo(int digitlen, int num, int *digitsinfo)
{
	//나누는 값 선언
	int divider;

	// 자릿수 개수 만큼 반복
	for (int i = 0; i < digitlen; i++) {
		//math 라이브러리 에서 거듭제곱 함수를 이용해 거듭제곱값을 10 ** I+1 로 받는다.
		divider = (int)pow(10, i + 1);
		//자릿수를 구해 1의자리를 맨 마지막에 마지막자리수는 1번째에 저장
		digitsinfo[digitlen - i -1] = (num % divider) / (divider / 10);
		//나머지 값을 빼준다.
		num -= num % divider;
	}
}

//내림차순 정렬
void SortedLower(int* digitsinfo, int size)
{
	int temp;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (digitsinfo[j] > digitsinfo[i]) {
				temp = digitsinfo[i];
				digitsinfo[i] = digitsinfo[j];
				digitsinfo[j] = temp;
			}
		}
	}
}

//30의 배수 인지 아닌지를 찾고 맞으면 위의 내림차순 정렬된 자릿수 정보를 이용해서
//30의 배수가 되는 수 중 최댓값을 출력한다.
void Find30N(int digitlen, int num, int* digitsinfo)
{
	//자릿수 합 저장 변수
	int sum = 0;

	// 만약 자릿수 중 0이 없으면 30의 배수가 아님으로 -1 출력
	//있으면 break로 탈풀
	for (int i = 0; i < digitlen; i++) {
		
		if (digitsinfo[i] == 0)
			break;
		
		if (i == digitlen - 1) {
			printf("-1");		
			return;
		}
	}


	//자릿수의 합 초기화
	for (int i = 0; i < digitlen; i++) {
		sum += digitsinfo[i];
	}

	//자릿수의 합이 3의 배수가 아니면 30의 배수가 아님으로 -1출력
	if (sum % 3 != 0) {
		
		printf("-1");
		return;
	}//맞으면 이미 내림차순으로 정렬된 숫자를 순서대로 출력한다.
	else {
		for (int i = 0; i < digitlen; i++) {
			printf("%d", digitsinfo[i]);
		}
	}

	return;
}