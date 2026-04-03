#define _CRT_SECURE_NO_WARNINGS
#include"menufunc.h"
#include"Phonenuminfo.h"
#include"menuinoutput.h"
#include"filefunc.h"

//참고사항 처음 데이터를 입력한 후에는 size크기는 함상 전화번호부의 정보 개수보다 1개 더 많다.

int main(void) {
	



	FILE *  Phonumfile = fopen("phonefile.txt", "rt");
	PhonInfo* phonenum;
	int size = 0;
	int* sizeptr = &size;
	
	//사용자가 선택할 메뉴 버튼 변수 선언 및 초기화, 이름 정보를 입력받고 함수에 전달할 배열 선언
	int opt = 0;
	char nameinfo[20];

	//전화번호부 배열을 가르킬 포인터 선언 및 동적할당, 전화번호부 크기와 크기 가르키는 포인터 선언
	
	phonenum = Load(Phonumfile, sizeptr);
	fclose(Phonumfile);
	
	Phonumfile = fopen("phonefile.txt", "wt");

	fseek(Phonumfile, 0, SEEK_SET);

	fclose(Phonumfile);

	//사용자가 5번 프로그램 종료를 선택하지 않는다면
	while (opt != 5) {
		
		//메뉴를 보여주는 함수 호출
		ShowMenu();
		//메뉴 버튼을 입력받는 함수 호출
		opt = GetMenuOption();

				//switch문을 이용한 각 메뉴의 실행
				switch (opt) {
					case 1 : {
						//전화번호부 내용 갱신
						phonenum = Insert(phonenum, sizeptr);
						 break;
					}
					case 2 : {
						//크기가 0인 경우에 대한 예외처리
						if (size  == 0 ) {
							puts("삭제할 정보가 없습니다");
							break;
						}
						//삭제할 이름을 입력받은 후 함수의 인자로 전달
						fputs("insert the name of a person you will delete info: ", stdout);
					  fgets(nameinfo, sizeof(nameinfo), stdin);
					 //fgets 함수 이용을 위한 개행 문자 제거 및 입력버퍼 비움
					  RemoveBsn(nameinfo);
					  RemoveLineBuf();
					 //전화번호부 내용 갱신
					  phonenum = Delete(phonenum, sizeptr, nameinfo);
					  break;
					}
					case 3 : {
						//정보를 출력할 사람의 이름을 입력받은 후 함수의 인자로 전달
						fputs("insert the name of a person you will print info: ", stdout);
						fgets(nameinfo, sizeof(nameinfo), stdin);
						//fgets 함수 이용을 위한 개행 문자 제거 및 입력버퍼 비움
						RemoveBsn(nameinfo);
						RemoveLineBuf();
						// 찾은 정보를 출력
						FindPhonenumInfo(phonenum, sizeptr, nameinfo);
						break;
					 }
					case 4: {
						// 전화번호부 상의 모든 정보를 출력한다.
						PrintAllPhonenumInfo(phonenum, sizeptr);
						break;
					}
				}	
			//사용자가 1~ 5 사이의 정수를 입력하지 않았을 때 경고문
			if (opt > 5 || opt < 1) {
					fputs("1~5사이의 정수를 입력하시오", stderr);
			}
	}

	Phonumfile = fopen("phonefile.txt", "wt");
	Save(Phonumfile, phonenum, sizeptr);


	//프로그램 종료 및 전화번호부에 할당된 동적 메모리 회수
	Exit();
	free(phonenum);
	//정상 종료
	return 0;
}