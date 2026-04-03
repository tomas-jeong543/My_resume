#ifndef __LiB__
#define __LiB__
#include"complexnum.h"
#include "inoput.h"
#include<stdio.h>
#endif 


//  복소수를 더하는 결과를 출력하는 함수
void ComNUmPlus(double realnum[2], double unrealnum[2], double* resulrealnum, double* resulunrealnum) {
	// 실수는 실수끼리 허수는 허수끼리 더하는 과정
	*resulrealnum = realnum[0] + realnum[1];
	*resulunrealnum = unrealnum[0] + unrealnum[1];
	//결과를 출력하는 과정
	fputs("합의 결과:", stdout);
	//결과를 출력하는 함수 호출
	PrintResultComnum(resulrealnum, resulunrealnum);
}

//  복소수를 곱하는 결과를 출력하는 함수
void ComNUmMul(double realnum[2], double unrealnum[2], double* resulrealnum, double* resulunrealnum) {

	// 실수부분과 허수부분을 따로 계산한다.
	*resulrealnum = realnum[0] * realnum[1] - unrealnum[0] * unrealnum[1];
	* resulunrealnum = unrealnum[0] * realnum[1] + unrealnum[1] * realnum[0];
	//결과를 출력하는 과정
	fputs("곱의 결과:", stdout);
	//결과를 출력하는 함수 호출
	PrintResultComnum(resulrealnum, resulunrealnum);
}
