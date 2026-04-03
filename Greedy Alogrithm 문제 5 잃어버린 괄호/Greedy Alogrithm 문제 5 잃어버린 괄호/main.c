/*문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 
입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"func.h"
// 문자열에서 필요한 정보인 숫자와 연산기호 정보를 추출하는 것은 c언어 기준 어느 정도 난이도가 있었으나
// 문제해결에 필요한 솔루션을 찾는 것은 간단히 -기호 등장 후 나머지 뒤에 있는 숫자를 다 빼면 된다는 것만
//안다면 쉽게 해결 가능한 문제였다, 해결에는 2시간이 걸렸다. 대부분 필요한 정보를 추출하는 데 사용함
int main(void) {
	
	// 문자열을 입력받을 배열 선언
	char String[51];
	// 숫자 개수 나타내는 변수, 배열의 크기 나타내는 변수, 연산기호 개수 저장 변수, 최소 결과값 저장 변수
	int numcount = 1,  StringSize= 0, calcount = 0, Min_Result;
	int* Num_data, * NUmDigits,* calinfo;
	String[50] = 0;
	
	//문자열 초기화
	for (int i = 0; i < 50; i++) {
		String[i] = 'k';
	}

	//문자열 입력 및 '\n'키 제거 위한 함수 실행
	printf("계산식을 입력하시오:단 입력으로 주어지는 식의 길이는 50보다 작거나 같아야 한다.");
	fgets(String, sizeof(String) - 1, stdin);
	RemoveBsn(String);
	
	//문자열의 길이 정보 획득
	StringSize = strlen(String);

	//문자열 길이 정보와 아스키 코드 표를 이용해 숫자의 개수를 파악한다. 이 때 숫자의 개수는 연산기호 + 1개라는 사실 이용
	for (int i = 0; i < StringSize; i++) {
			if (String[i] < 48 ||  String[i] > 57 ) {
				numcount += 1;
		}
	}
	
	//숫자의 개수는 연산기호 + 1개라는 사실 이용
	calcount = numcount - 1;

	//숫자의 개수와 연산기호 개수를 이용한 숫자의 자리수 정보, 숫자 정보,연산기호 정보를 가르키는 포인터에 
	//메모리 동적 할당
	NUmDigits = (int*)malloc(sizeof(int) * numcount);
	Num_data = (int*)malloc(sizeof(int)* numcount);
	calinfo = (int*)malloc(sizeof(int) * calcount);
	//예외 처리
	if (Num_data == NULL || NUmDigits == NULL || calinfo == NULL) {
		puts("오류 발생");
		return -1;
	}

	// 연산 기호 정보를 GetCalInfo함수를 통해 얻는다.
	calinfo = GetCalInfo(calinfo, String, StringSize);
	//숫자의 자릿수 정보를 GetNUmdigitsInfo함수를 통해 얻는다.
	NUmDigits = GetNUmdigitsInfo(NUmDigits, String, StringSize);

	//숫자 정보 0으로 초기화
	for (int i = 0; i < numcount; i++) {
		Num_data[i] = 0;
	}

	//숫자 정보를 숫자의 자리수 정보를 이용해 GetNUmInfo 함수를 통해 구한다.
	Num_data = GetNUmInfo(NUmDigits, String, numcount, Num_data);

	//숫자 정보와 연산 기호 정보를 통해 괄호를 이용한 연산 결과의 최솟값을 구하고 출력한다.
	Min_Result = FindMinResult(calinfo, Num_data, calcount);
	printf("최소 계산 결과: %d\n", Min_Result);

	free(Num_data);
	free(NUmDigits);
	free(calinfo);
	return 0;
}