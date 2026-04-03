#include<stdbool.h>
// 함수에 대한 정보는 linefunc.c에 자세히 설명되어 있다.
void RemoveLineBuf(void);
bool DetOverlap(Lineinfo* linedata, Lineinfo lineins, int *datasizeptr);
Lineinfo* CheckOverlapInsideData(Lineinfo* linedata, int * datasizeptr, int idx);
int FindLenSum(Lineinfo* lineinfo, int datasize);