//모든 도미노를 넘어뜨리기 위한 최소 도미노 수를 구하기 위한 함수들
#include"Domino.h"
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"Memory.h"
//main에서 도미노가 다 넘어졌는지 확인하는 함수로 다 넘어질 때까지 Setimfo함수가 실행된다.
bool DetEnd(int* Detcopy, int size);
// 한도미노를 오른쪽으로 쓰러트렸을 때 쓰러지는 도미노수를 개산해 포인터를 이용해 값을 집어 넣는 함수
void FindRightWay(Domino* dominfo, int* Breknuminfo, int* Detcopy,
	int size, int startpoint, bool* dirptr, int domidx);
// 한도미노를 왼쪽으로 쓰러트렸을 때 쓰러지는 도미노수를 개산해 포인터를 이용해 값을 집어 넣는 함수
void FindLeftWay(Domino* dominfo, int* Breknuminfo, int* Detcopy,
	int size, int startpoint, bool* dirptr, int domidx);
// 가장 많은 도미노를 쓰러트리는 도미노를 쓰러트리면서 쓰러지는 도미노의 정보를 갱신하는 함수
void ChangeDet(Domino* dominfo, int* Breknuminfo, int* Detcopy,
	int size, int startpoint, bool* dirptr);
//가장 많은 도미노를 쓰러트리는 도미노의 위치 정보를 넘기는 함수
int FindMaxNUmIdx(Domino* dominfo, int* Breknuminfo, int* Detcopy, int size, bool* dirptr);

// 위의 4개의 함수들을 이용해 도미노의 현재 상황에서 가장 많은 도미노를 넘어뜨릴 수 있는
//도미노를 넘어트리고 도미노 정보를 갱신하는 함수 
void SetImfo(Domino* dominfo, int* Breknuminfo, int* Detcopy,
	int size, bool* dirptr);
