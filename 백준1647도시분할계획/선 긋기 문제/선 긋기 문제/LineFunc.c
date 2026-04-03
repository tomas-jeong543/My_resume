#include<stdbool.h>
#include<stdio.h>
#include"Line.h"
#include<stdlib.h>

// 입력 버퍼를 비우는 함수
void RemoveLineBuf(void) 
{
	while (getchar() != '\n');
}

// 새로 입력받은 선의 정보와 기존 선의 정보를 비교해 중복이면 true를 거짓이면 false를 반환한다.
// 만약에 중복되면 기존에 있는 선의 범위를 중복되는 선과 합친다.
bool DetOverlap(Lineinfo * linedata, Lineinfo lineins, int *datasizeptr) 
{
	// 중복 여부에 따라 참과 거짓을 반환할 변수 선언, 메모리 재할당위해 사용할 Lineinfo* 형 변수 선언
	bool det = false;
	Lineinfo* linedatarealloc;
	//만약 3개의 선을 입력 시에 1,2번 선이 서로 겹치지 않고 3번 선이 1,2번 선과 겹친다면
	// 두 개의 선 모두 다 범위를 확장되는 일이 일어날 수 있다 따라서 이를 막기위해서
	// 두 선을 합쳤는지 확인 여부가 필요하다 따라서 checkchange 값을 통해 이 선이 이미 병합되었는지를 나타낸다.
	bool checkchange = false;


	// 새로 입력된 선의 끝점이 기존의 저장된 중복되지 않는 선들의 범위 안에 들어 있는지 확인
	for (int i = 0; i < *datasizeptr; i++) {
		if (lineins.endpoint >= linedata[i].startpoint && lineins.endpoint
			<= linedata[i].endpoint) {
			
			det = true;
			
			// 입력된 선이 병합이 되었으면 병합하지 않고 병합되지 않았으면 서로 병합한다.
			if (linedata[i].startpoint > lineins.startpoint && !checkchange) {
				linedata[i].startpoint = lineins.startpoint;
				checkchange = true;
			}
			
		}
		// 새로 입력된 선의 시작점이 기존의 저장된 중복되지 않는 선들의 범위 안에 들어 있는지 확인
		if (lineins.startpoint >= linedata[i].startpoint && 
			lineins.startpoint <= linedata[i].endpoint) {
			
			det = true;
			// 입력된 선이 병합이 되었으면 병합하지 않고 병합되지 않았으면 서로 병합한다.
			if (linedata[i].endpoint < lineins.endpoint && !checkchange) {
				linedata[i].endpoint = lineins.endpoint;
				checkchange = true;
			}

		}
	}
	//변환되었는지 알려주는 변수를 반환한다.
	return det;
}

//한 선에 대해 lineinfo내에 그 선과 중복된 선들을 찾아 병합하고 병합된 내용에 따라 변한 lineinfo의 정보를 다시 반환받는다.
Lineinfo* CheckOverlapInsideData(Lineinfo * linedata, int *datasizeptr, int idx)
{
	//중복된 선이 있는지 여부를 나타내는 변수 건언
	bool DetEnd = false;
	//중복된 경우가 있을 때 메모리 재할당 시 포인터의 끝에 있는 자료가 사라짐으로 이를 저장하는 변수 선언 및 초기화
	Lineinfo tempsave = { 0, 0 };
	// 비교할 선을 저장할 변수
	Lineinfo tempins = { 0, 0 };
	//메모리 재할당을 위한 Lineinfo*변수
	Lineinfo* linedatarealloc;

		
		// 비교할 선을 저장할 변수 초기화
		tempins.startpoint = linedata[idx].startpoint;
		tempins.endpoint = linedata[idx].endpoint;

		// 비교할 선에 중복된 선이 있는 경우 동안 계속 반복하라는 뜻
		while (!DetEnd) {

			//동적 메모리 할당 오류
			if (linedata == NULL) {
				puts("linedataerror");  
				exit(1);
			}
				//포인터의 끝에 있는 자료가 사라짐으로 이를 저장하는 변수 초기화
				tempsave.startpoint = linedata[*datasizeptr - 1].startpoint;
				tempsave.endpoint = linedata[*datasizeptr - 1].endpoint;
			
			//기준이 되는 선 이후 인덱스에 대해 비교한다.
			//이렇게 하는 이유는 main에서 idx를 0 ~ 데이터의 크기 -1 까지 순차적으로
			//기준선을 주기 때문에 모든 선들이 다 비교가 되기 때문이다.	
			for (int i = idx + 1; i < *datasizeptr; i++) {
				
				//초기값 설정
				DetEnd = true;


				// 기준선의 시작점이 기존의 저장된 선들의 범위 안에 들어 있는지 확인
				if (linedata[i].startpoint > tempins.startpoint 
					&& linedata[i].startpoint < tempins.endpoint) {
					// 범위 안에 있으면 중복이다.
					DetEnd = false;

					// 두 선 병합
					if (linedata[i].endpoint > tempins.endpoint) {
						tempins.endpoint = linedata[i].endpoint;
					}
				}

				// 기준선의 끝점이 기존의 저장된 선들의 범위 안에 들어 있는지 확인
				if(linedata[i].endpoint > tempins.startpoint && 
					linedata[i].endpoint < tempins.endpoint) {
					// 범위 안에 있으면 중복이다.
					DetEnd = false;

					// 두 선 병합
					if (linedata[i].startpoint <  tempins.startpoint) {
						tempins.startpoint = linedata[i].startpoint;
					}
				}

				
			// 만약 모든 선과 중복여부를 확인했고 모든 남아있는 선과 중복이 아닌 경우 그 정보를 반환한다.	
			 if( i == *datasizeptr - 1 && DetEnd) {
					return linedata;
				}
				else if(!DetEnd) {
					//중복된 선이 있는 경우 중복된 선은 이미 병합되었음으로 중복된 선의 내용을 포인터의
					//맨 끝에 있는 선의 내용으로 바꾸어준다.
					linedata[i].startpoint = tempsave.startpoint;
					linedata[i].endpoint = tempsave.endpoint;

					// 메모리를 재할당하며 선의 정보를 한개 줄이고 크기 정보를 갱신한다.
					linedatarealloc = (Lineinfo*)realloc(linedata, sizeof(Lineinfo) * (*datasizeptr - 1));
					*datasizeptr -= 1;
					if (linedatarealloc != NULL) {
						linedata = linedatarealloc;
						// 병합된 선을 인덱스 정보를 이용해 기존 선에 집어 넣는다.
						linedata[idx].startpoint = tempins.startpoint;
						linedata[idx].endpoint = tempins.endpoint;
					}
				}
			
			}
		}
		// 만약 모든 선과 중복여부를 확인했고 모든 남아있는 선과 중복이 아닌 경우 그 정보를 반환한다.	
		return linedata;
}

// 서로 중복되지 않는 선들의 길이의 총합을 구해 반환하는 함수
int FindLenSum(Lineinfo * lineinfo, int datasize) 
{
	// 길이 변수를 저장하는 변수와 그 총합을 저장하는 변수 선언
	int lensum = 0;
	int linelen;

	// 있는 선의 개수만큼 선의 길이를 구해 총합에 더한다.
	for (int i = 0; i < datasize; i++) {
		linelen = lineinfo[i].endpoint - lineinfo[i].startpoint;
		lensum += linelen;
	}
	
	// 선의 길이의 총합 반환
	return lensum;
}