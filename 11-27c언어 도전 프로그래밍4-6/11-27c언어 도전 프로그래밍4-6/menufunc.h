//메뉴의 기능을 구현하는 함수들을 저장하는 해더파일로 전화번호부 구조체에 관한 정보를 가지고 있다.
#include "Phonenuminfo.h"

PhonInfo* Insert(PhonInfo* phone, int* size);
PhonInfo* Delete(PhonInfo* phone, int* size, char name[20]);
void FindPhonenumInfo(PhonInfo* phone, int* size, char name[20]);
void PrintAllPhonenumInfo(PhonInfo* phone, int* size);
int FindPersonLocation(PhonInfo* phone, int* size, char name[20]);
void Exit(void);
