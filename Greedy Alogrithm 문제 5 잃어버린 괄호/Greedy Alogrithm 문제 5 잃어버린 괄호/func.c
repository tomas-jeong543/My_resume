#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
// 앤터 키를 제거하고 문자열의 끝에 null을 너어주는 함수
void RemoveBsn(char * str)
{
	int len = strlen(str);
	str[len - 1] = 0;
}

// 각 숫자의 자릿수 정보를 얻어 포인터에 저장해 그 정보를 반환하는 함수
int* GetNUmdigitsInfo(int* NUmDigits, char* str, int StringSize)
{
	//각 숫자의 자릿수 정보를 가르키는 배열의 인덱스 정보
	int NUmdigits_idx = 0;
	// 시작점과 끝점 선언
	int startidx = 0;
	int endidx;
	// 문자열의 모든 문자에 개수 만큼 반복
	for (int i = 0; i < StringSize; i++) {
		
		//만약 그 문자가 숫자가 아니라면 
		if (str[i] < 48 || str[i] > 57 ) {
			//그 전 숫자가 숫자의 끝임으로 그 인덱스 정보 저장
			endidx = i - 1;
			//숫자의 길이를 시작점과 끝점을 이용해 구함
			NUmDigits[NUmdigits_idx++] = endidx - startidx + 1;
			//시작점 초기화
			startidx = endidx + 2;
		}// 만약 문자열의 마지막 인덱스에 도달했다면
		else if (i == StringSize - 1) {
			//숫자의 끝은 곳 그 인덱스이다.
			endidx = i;
			//숫자의 길이를 시작점과 끝점을 이용해 구함
			NUmDigits[NUmdigits_idx++] = endidx - startidx + 1;
		}
	}

	return NUmDigits;

}
//숫자의 자릿수 정보를 이용해 숫자를 구해 저장하고 저장한 포인터를 반환하는 함수
int* GetNUmInfo(int* NUmDigits, char* str, int numcount, int * NumInfo)
{
	//문자열 정보를 저장하는 인덱스 변수와 자릿수 나타내는 변수 선언
	int stridx = 0;
	int digits = 0;

	//숫자의 개수 만큼 반복
	for (int i = 0; i < numcount; i++) {
		//자릿수에 따라 digit를 digit - 1 개 만큼 *10해 준다.
		digits = pow(10, NUmDigits[i] - 1);
		
		//각 숫자의 자릿수 만큼 반복
		for (int j = 0; j < NUmDigits[i]; j++) {
			
			// 문자열의 문자 정보가 숫자라면
			if (str[stridx] >= 48 && str[stridx] <= 57 ) {
				// 아스키코드를 이용해 문자열 정보를 정수 정보로 바꾸고 자릿수에 맞게 digits을 곱한다.
				NumInfo[i] += (str[stridx] - '0') * digits;
				
				//만약 다음 문자가 숫자가 아니라면 그 문자는 건너뛴다,
				if (str[stridx + 1] > 57 || str[stridx + 1] < 48) {
					stridx += 2;
				}
				else//문자열 정보가 숫자라면 다음 문자열로 이동한다.
					stridx += 1;
			}
			else // 문자열의 문자 정보가 숫자가 아니면 그 문자는 건너뛴다.
			{
				stridx += 1;
			}
			//위의 for문이 반복됨에 따라 자릿수가 1씩 낮아짐으로 digits도 10으로 나눈다.
			digits /= 10;
		}
		
	}

	return NumInfo;
}

// +-연산기호를 위치에 따라 저장하고 저장된 배열을 반환하는 함수
int* GetCalInfo(int* calinfo, char* str, int StringSize)
{

	int calinfoidx = 0;

	for (int i = 0; i < StringSize; i++) {

		// 아스키 코드를 이용해 +면 1 저장
		if (str[i] == 43) {
			calinfo[calinfoidx++] = 1;
			}//아니면 -1 저장한다.
		else if (str[i] == 45) {
			calinfo[calinfoidx++] = -1;
		}
	}

	return calinfo;
}

// 연산 기호 정보와 숫자 정보를 이용해 계산에 괄호를 씌워 최솟값을 만들어 반환하는 함수
int FindMinResult(int * calinfo, int * numinfo, int calnum)
{
	//첫 번째 숫자 정보 저장
	int minnum = numinfo[0];

	//연산 기호가 -가 나오기 전까지 다 더하고 -가 나오면 그 이후 숫자는 다 빼면된다.
	for (int i = 0; i < calnum; i++) {
		if (calinfo[i] == -1) {
			for (int j = i + 1; j < calnum + 1; j++) {
				minnum -= numinfo[j];
			}
			return minnum;
		}
		else {
				minnum += numinfo[i + 1];
			}
		}

	return minnum;
}