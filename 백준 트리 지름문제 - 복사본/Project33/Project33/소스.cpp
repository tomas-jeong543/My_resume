#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
int seating[5] = { s0,s1,s2,s3,s4 };
int print_seats();
int researve(int seat);
int cancel(int seat);

int main(void)
{
	
	int i;
	int select;
	do
	{
		printf("1--좌석 확인하기\n");
		printf("2--예약하기\n");
		printf("3--예약 취소하기\n");
		printf("4--종료하기\n\n");
		printf("메뉴를 선택하시오:");
		scanf("%d", &select);
		printf("\n");
		if (select == 1)
				print_seats();
		else if (select == 2)
		{
			printf("예약을 원하는 자리는?");
			scanf("%d", &i);
			researve(i);
			seating[i] = 1;
			print_seats();
		}
		else if (select == 3)
		{
			printf("예약취소를 원하는 자리는?");
			scanf("%d", &i);
			cancel(i);
			seating[i] = 0;
			print_seats();

		}
	} while (select != 4);

	
	printf("이용해 주셔서 감사합니다.\n");

	return 0;
}

 int print_seats()
{
	
	 printf("0 1 2 3 4\n");
	 printf("---------\n");
	 for (int i = 0; i < 5; i++)
		 printf("%d ", seating[i]);
	 printf("\n\n");
	 return 0;
}

 int researve(int seat)
 {
	 
	int i = seat;
	
	 if (seating[i] == 0)
	 {
		 seating[i] = 1;
		 printf("예약이 완료되었습니다.\n");
		 return i;
	 }
	 else 
	 {
		 printf("이미 예약된 자리입니다.\n");
		 return -1;
	 }
	 
 }
 int cancel(int seat)
 {
	 int i = seat;

	 if (seating[i] == 1)
	 {
		 seating[i] = 0;
		 printf("예약취소가 완료되었습니다.\n");
		 return i;
	 }
	 else
	 {
		 printf("예약되지 않은 자리입니다.\n");
		 return -1;
	 }
 }