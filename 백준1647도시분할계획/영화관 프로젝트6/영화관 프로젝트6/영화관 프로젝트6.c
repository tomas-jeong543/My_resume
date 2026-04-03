#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
FILE* fp1;
FILE* fp;
int load_reservation_info(int s[][5]);
int save_reservation_info(int s[][5]);
int check_login(char id[10], char password[10], struct user_info user[10]);
int load_user_info(struct user_info user[10]);
int print_seats(int seating[3][5]);
int researve(int seating[3][5], char row, int col, int seat_num, struct user_info user[10]);
int cancel(int seating[3][5], char row, int col, int seat_num, struct user_info user[10]);
struct user_info {
	int id_num;
	char id[10];
	char password[10];
};


int main(void)
{
	struct user_info user[10];
	int seating[3][5] = {
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 }

	};
	load_reservation_info(seating);
	int col = 0, seat_num;
	int n;
	char c;
	char row;
	char id[10];
	char pw[10];
	int select;
	if (load_user_info(user) == -1)
	{
		printf("ERROR");
		return 0;
	}
	//for (n = 0; n < 10; n++)
		//printf("%d %s %s\n", user[n].id_num, user[n].id, user[n].password);
	while (1) {
		printf("로그인을 하세요.\n");
		printf("id_num: ");
		scanf("%s", id);
		printf("password: ");
		scanf("%s", pw);

		if (check_login(id, pw, user) == -2)
			printf("id는 존재하지만 password가 다릅니다.\n");
		else if (check_login(id, pw, user) == -1)
			printf("id가 존재하지 않습니다.\n");
		else break;

	}
	seat_num = check_login(id, pw, user);

	printf("%s님 반갑습니다.\n", id);

	do
	{
		printf("1--좌석 확인하기\n");
		printf("2--예약하기\n");
		printf("3--예약 취소하기\n");
		printf("4--다른 사용자로 로그인하기\n");
		printf("5--종료하기\n\n");
		printf("메뉴를 선택하시오:");
		scanf("%d", &select);
		printf("\n");

		if (select == 1)
			print_seats(seating);
		else if (select == 2)
		{
			printf("예약을 원하는 자리는(예-A2)?");
			while ((c = getchar()) != '\n' && c != EOF) {};
			scanf("%c%d", &row, &col);

			researve(seating, row, col, seat_num, user);
			print_seats(seating);
		}
		else if (select == 3)
		{
			printf("예약취소를 원하는 자리는(예-A2)?");
			while ((c = getchar()) != '\n' && c != EOF) {};
			scanf("%c%d", &row, &col);
			cancel(seating, row, col, seat_num, user);
			print_seats(seating);

		}
		else if (select == 4)
		{
			while (1) {
				printf("로그인을 하세요.\n");
				printf("id_num: ");
				scanf("%s", id);
				printf("password: ");
				scanf("%s", pw);

				if (check_login(id, pw, user) == -2)
					printf("id는 존재하지만 password가 다릅니다.\n");
				else if (check_login(id, pw, user) == -1)
					printf("id가 존재하지 않습니다.\n");
				else break;

			}
			seat_num = check_login(id, pw, user);

			printf("%s님 반갑습니다.\n", id);


		}
	} while (select != 5);

	save_reservation_info(seating);
	printf("이용해 주셔서 감사합니다.\n");

	return 0;
}

int print_seats(int seating[3][5])
{

	printf("  I 0  1  2  3  4\n");
	printf("-----------------\n");
	for (int j = 0; j < 3; j++)
	{
		printf("%c I", j + 65);
		for (int i = 0; i < 5; i++)
			printf(" %d ", seating[j][i]);
		printf("\n");
	}
	printf("\n\n");
	return 0;
}
int researve(int seating[3][5], char row, int col, int seat_num, struct user_info user[10])
{



	if (seating[row - 65][col] == 0)
	{

		printf("예약이 완료되었습니다.\n");
		seating[row - 65][col] = seat_num;
		return 0;
	}
	else
	{
		printf("이미 예약된 자리입니다.\n");
		return -1;
	}

}
int cancel(int seating[3][5], char row, int col, int seat_num, struct user_info user[10])
{


	if (seating[row - 65][col] == seat_num)
	{

		printf("예약취소가 완료되었습니다.\n");
		seating[row - 65][col] = 0;
		return 0;
	}
	else
	{
		printf("예약되지 않은 자리입니다.\n");
		return -1;
	}
}

int load_user_info(struct user_info user[10])
{
	int i, j, k, least, c = 0;
	char temp[20];
	if ((fp = fopen("user_data.txt", "r")) == NULL)
	{
		return -1;
	}
	else
	{
		fp = fopen("user_data.txt", "r");
		for (i = 0; i < 10; i++)
		{
			fscanf(fp, " %d %s %s\n", &user[i].id_num, user[i].id, user[i].password);
			
		}

		for (j = 0; j < 9; j++)
		{
			least = j;
			for (k = j + 1; k < 10; k++)
			{
				if (strcmp(user[least].id, user[k].id) > 0)
				{
					least = k;
				}
				
			}
			
			strcpy(temp, user[j].id);
			strcpy(user[j].id, user[least].id);
			strcpy(user[least].id, temp);
			strcpy(temp, user[j].password);
			strcpy(user[j].password, user[least].password);
			strcpy(user[least].password, temp);
			c = user[j].id_num ;
			user[j].id_num = user[least].id_num;
			user[least].id_num = c;
			
		}
		user[9].id_num = 19;
		return 10;	
	}

}

int check_login(char id[10], char password[10], struct user_info user[10])
{
	int low, high, middle;

	low = 0;
	high = 10;

	while (low <= high)
	{
		middle = (low + high) / 2;
		if (strcmp(id, user[middle].id) == 0)
		{
			if (strcmp(password, user[middle].password) == 0)
				return user[middle].id_num;
			else
				return -2;
		}
		else if (strcmp(id, user[middle].id) > 0)
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;
}
int load_reservation_info(int s[][5])
{
	int n = 0;

	if ((fp1 = fopen("reservation_data.txt", "r")) == NULL)
	{
		return -1;
	}
	else
	{
		for (n = 0; n < 3; n++)
			fscanf(fp1, " %d %d %d %d %d\n", &s[n][0], &s[n][1], &s[n][2], &s[n][3], &s[n][4]);
		
		return 0;
	}
}
int save_reservation_info(int s[][5])
{
	int n;

	if ((fp1 = fopen("reservation_data.txt", "w")) == NULL)
	{
		return -1;
	}
	else
	{
		
		for (n = 0; n < 3; n++)
			fprintf(fp1, "%d %d %d %d %d\n", s[n][0], s[n][1], s[n][2], s[n][3], s[n][4]);
		
		return 0;
	}
}

	