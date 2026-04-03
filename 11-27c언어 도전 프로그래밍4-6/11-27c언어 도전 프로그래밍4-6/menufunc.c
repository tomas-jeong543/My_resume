#ifndef __LIBRARY__
#define __LIBRARY__
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Phonenuminfo.h"
#include"menuinoutput.h"
#include"menufunc.h"
#endif 

// 이름과 전화번호를 입력해 저장하는 함수
PhonInfo* Insert(PhonInfo* phone, int* size)
{
	puts("Insert");

	// 크기가 0인 경우 크기를 1로 늘리고 전화번호부가 NULL인 경우에 대비해 다시 메모리를 할당한다.
	if (*size == 0) {
		*size += 1;
		phone = (PhonInfo*)malloc(sizeof(PhonInfo));
	}

	// phone 전화번호부의 위치 정보를 저장하는 phone2와 백업 데이터를 저장할 pcopy를 선언
	PhonInfo* phone2 = phone;
	PhonInfo* pcopy = (PhonInfo*)malloc(sizeof(PhonInfo) * (*size));

	//pcopy 메모리 할당 실패에 대한 예외 처리
	if (pcopy == NULL) {
		puts("오류0 발생");
		exit(1);
	}
	
	//크기가 1인 경우 데이터 백업 없이 그냥 데이터를 입력받고 전화번호부를 반환한다. 
	if (*size == 1 ) {
		fputs("Input name: ", stdout);
		fgets(phone[*size - 1].name, sizeof(phone[*size - 1].name) - 1, stdin);
		RemoveLineBuf();
		RemoveBsn(phone[*size - 1].name);

		fputs("Input Tel NUmber: ", stdout);
		fgets(phone[*size - 1].phonenum, sizeof(phone[*size - 1].phonenum), stdin);
		RemoveLineBuf();
		RemoveBsn(phone[*size - 1].phonenum);
		*size += 1;
		puts("Data Inserted");
		return phone;
	}

	//크기가 1보다 큰 경우에는 전화번호부를 pcopy에 백업
	for (int i = 0; i < *size - 1; i++) {
		strcpy_s(pcopy[i].name, sizeof(pcopy[i].name), phone[i].name);
		strcpy_s(pcopy[i].phonenum, sizeof(pcopy[i].phonenum), phone[i].phonenum);
	}
	// 임시 주소에 전화번호부의 크기를 재할당
	phone2 = (PhonInfo*)realloc(phone2, sizeof(PhonInfo) * ( *size));

	//재할당 실패하지 않은 경우 phone2주소를 phone에 저장함 메모리 누수가 방지됨 
	if(phone2 != NULL) {
		phone = phone2;
	}

	//pcopy의 데이터를 다시 phone에 다시 넣어준다.
	for (int i = 0; i < *size - 1; i++) {
		strcpy_s(phone[i].name, sizeof(phone[i].name), pcopy[i].name);
		strcpy_s(phone[i].phonenum, sizeof(phone[i].phonenum), pcopy[i].phonenum);
	}

	//추가할 내용을 배열의 끝에 기입한다.
	fputs("Input name: ", stdout);
	fgets(phone[*size - 1].name, sizeof(phone[*size - 1].name), stdin);
	RemoveLineBuf();
	RemoveBsn(phone[*size - 1].name);

	fputs("Input Tel NUmber: ", stdout);
	fgets(phone[*size - 1].phonenum, sizeof(phone[*size - 1].phonenum), stdin);
	RemoveLineBuf();
	RemoveBsn(phone[*size - 1].phonenum);

	puts("Data Inserted");
	// 전화번호부 크기를 1 증가시킨다.
	*size += 1;

	// 백업 데이터 저장하는 동적 메모리를 회수한다.
	free(pcopy);
	return phone;

}

//이름을 통해 정보를 삭제하는 함수
PhonInfo* Delete(PhonInfo * phone, int* size, char name[20])
{	
	// 삭제하려는 이름의 정보가 있는 구조체의 위치정보를 저장한다.
	int posidx = FindPersonLocation(phone, size, name);
	int pcopyidx = 0;

	puts("Delelte");


	// 삭제하려고 하는 이름이 전화번호부에 없는 경우 -1을 반환함으로
	//그 경우에는 그냥 다시 원래 전화번호부를 반환한다.
	if (posidx == -1) {

		return phone;
	}

	// 크기가 2보다 작으면 전화번호부의 내용은 1개 이하임으로 전화번호부 크기를 0으로 초기화하고
	// NULL을 반환한다.
	 if ( *size <  2) {
		*size = 0;
		puts("Data Delelted");
		return NULL;
	}

	 // phone 전화번호부의 위치 정보를 저장하는 phone2와 삭제 후 데이터를 저장할 pcopy
	 // 하지만 pcopy는 마지막 구조체 정보가 쓰레기 값으로 차 있어 그쓰레기 값을 제외한
	 //나머지 전화번호부 정보만 갖는 pcopy2를 선언 및 할당한다.
	PhonInfo* phone3 = phone;
	PhonInfo* pcopy = (PhonInfo*)malloc(sizeof(PhonInfo) * (*size - 1));
	PhonInfo* pcopy2 = (PhonInfo*)malloc(sizeof(PhonInfo) * (*size - 2));
	
	
	// 동적 메모리 할당 실패에 대한 예외 처리
	while (pcopy == NULL || pcopy2 == NULL ) {
		pcopy = (PhonInfo*)malloc(sizeof(PhonInfo) * (*size - 1));
		pcopy2 = (PhonInfo*)malloc(sizeof(PhonInfo) * (*size - 2));
	}


	// 삭제 정보를 제외한 나머지 전화번호부 정보를 기존 전화번호부로부터 복사받는다.
	for (int i = 0; i < *size - 1; i++) {

		if (i != posidx) {
			strcpy_s(pcopy[pcopyidx].name, sizeof(pcopy[pcopyidx].name), phone3[i].name);
			strcpy_s(pcopy[pcopyidx].phonenum, sizeof(pcopy[pcopyidx].phonenum), phone3[i].phonenum);
			pcopyidx += 1;
		}
	}

	
	// 쓰레기 값을 제외한 나머지 전화번호부 정보를 pcopy 전화번호부로부터 복사받는다.
	for (int j = 0; j < ( *size - 2); j++) {
		strcpy_s(pcopy2[j].name, sizeof(pcopy2[j].name), pcopy[j].name);
		strcpy_s(pcopy2[j].phonenum, sizeof(pcopy2[j].phonenum), pcopy[j].phonenum);
	}

	//전화번호부 크기를 1 줄인다.
	*size -= 1;
	puts("Data Delelted");
	// 반환할 정보를 제외한 나머지 동적 메모리 할당을 해제
	free(phone3);
	free(pcopy);
	return pcopy2;

}

// 이름을 이용해 정보의 위치를 찾아 정보를 출력하는 함수
void FindPhonenumInfo(PhonInfo* phone, int* size, char name[20])
{
	//정수형 변수에 찾으려는 이름의 정보가 있는 구조체의 위치정보를 저장한다.
	puts("Serach");
	puts("Data Serached");
	int posidx = FindPersonLocation(phone, size, name);

	// 만약 찾는 정보가 없으면 함수를 종료한다.
	if (posidx == -1) {
		printf("\n");
		return;
	}

	//찾는 정보를 출력한다.
	printf("Name: %s Tel: %s\n", phone[posidx].name, phone[posidx].phonenum);
	puts("\n");
}
// 저장된 모든 이름과 전화번호를 출력하는 함수
void PrintAllPhonenumInfo(PhonInfo* phone, int* size)
{
	puts("Print All");
	puts("");

	// 출력할 경우가 없는 경우에 대한 예외처리
	if ( *size <  1) {
		puts("출력할 내용이 없습니다.");
		return;
	}

	//전화번호부 상의 모든 내용 출력
	for (int i = 0; i < (* size - 1 ); i++) 
		printf("Name: %s Tel: %s\n", phone[i].name, phone[i].phonenum);
	puts("\n");
}

// 프로그램을 종료하는 함수
void Exit() {
	puts("Exit");
	puts("전화번호 관리 프로그램을 종료합니다.");
	return;
}
// 이름을 이용해 정보의 위치를 찾아 숫자로 반환하는 함수
int FindPersonLocation(PhonInfo* phone, int* size, char name[20]) {

	//찾는 이름의 길이와 전화번호부의 저장된 이름의 길이를 저장할 변수 2개선언
	unsigned int len1, len2;
	
	// len2는 찾는 이름의 길이
	len2 = strlen(name);

	//전화번호부의 정보개수 만큼 전화번호부의 이름의 길이를 1차 비교해 길이가 같으면
	//문자열 내용을 2차 비교하여 같으면 구조체 정보의 위치를 잔환한다.
	for (int i = 0; i < *size - 1; i++) {
		
		len1 = strlen(phone[i].name);
		
		if (len1 == len2) {
			for (int j = 0; j < len1; j++) {
				if (!((phone[i].name[j]) == name[j]))
						break;
				
				if (j == len1 - 1)
					return i;
			}
		}
	}
	
	//이름이 전화번호부에 없는 경우에 대한 예외처리
	puts(" 그런 이름을 가진 사람이 전화번호부에 없습니다.");
	
	return -1;
}
