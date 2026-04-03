#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct user_info {
	int id_num;	//회원번호
	char id[10]; //회원 아이디 10자이내
	char password[10]; // 10자이내
};
int check_login(int id, int password);
int load_user_info(struct user[10]);
int print_seats(int seating[3][5]);
int researve(int seating[3][5], int row, int col,int id);
int cancel(int seating[3][5], int row, int col, int id);



int main(void)
{
	struct user_info user[10];

	int seating[3][5] = {
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 }

	};
	int i, j,id,pw;
	int select;
	load_user_info( user);
	do {
		printf("로그인을 하세요.\n");
		printf("id_num: ");
		scanf("%d", &id);
		printf("password: ");
		scanf("%d", &pw);
		if (check_login(id, pw) == -2)
			printf("id는 존재하지만 password가 다릅니다.\n");
		else if(check_login(id, pw) == -1)
			printf("id가 존재하지 않습니다.\n");
	} while (check_login(id, pw) != id);

	printf("%d님 반갑습니다.\n", id);
	
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
			print_seats(seating);
		else if (select == 2)
		{
			printf("예약을 원하는 자리는(행 열)?");
			scanf("%d %d", &i, &j);
			researve(seating, i, j, id);
			seating[i][j] = id;
			print_seats(seating);
		}
		else if (select == 3)
		{
			printf("예약취소를 원하는 자리는(행 열)?");
			scanf("%d %d", &i, &j);
			cancel(seating, i, j, id);
			seating[i][j] = 0;
			print_seats(seating);

		}
	} while (select != 4);


	printf("이용해 주셔서 감사합니다.\n");

	return 0;
}

int print_seats(int seating[3][5])
{

	printf("  I 0  1  2  3  4\n");
	printf("-----------------\n");
	for (int j = 0; j < 3; j++)
	{
		printf("%d I", j);
		for (int i = 0; i < 5; i++)
			printf(" %d ", seating[j][i]);
		printf("\n");
	}
	printf("\n\n");
	return 0;
}
int researve(int seating[3][5], int row, int col, int id)
{
	int i, j;
	i = row;
	j = col;


	if (seating[i][j] == 0)
	{

		printf("예약이 완료되었습니다.\n");
		return 0;
	}
	else 
	{
		printf("이미 예약된 자리입니다.\n");
		return -1;
	}

}
int cancel(int seating[3][5], int row, int col, int id)
{
	int i, j;
	i = row;
	j = col;

	if (seating[i][j] == id)
	{

		printf("예약취소가 완료되었습니다.\n");
		return 0;
	}
	else
	{
		printf("예약되지 않은 자리입니다.\n");
		return -1;
	}
}

int load_user_info(struct user[10])
{
	for (int i = 0; i < 10; i++)
	{
		user[i].id_num = (i + 1) * 10;
		sprintf(user[i].id_num, "user%d", i);
		sprintf(user[i].password, "user%d", i);
	}
	return 0;
} 

int check_login(int id, int password)
{
	int low, high, middle;
	low = 0;
	high = 15;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if ((id == user[middle].id_num))
		{
			if (password == user[middle].password)
				return id;
			else
				return -2;
		}
		else if (id > user[middle].id_num)
			low = middle + 1;
		else
			high = middle - 1;

	}
	return -1;
}