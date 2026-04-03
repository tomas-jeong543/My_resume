#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

#define S_SIZE 50
typedef struct NODE_t {
	char title[S_SIZE];
	float score;
	struct NODE_t* link;
}NODE;
// 주의 할 점 맨 앞,중간, 맨뒤 일 떄 중요


int main(void)
{
	NODE* head = NULL;
	NODE* tail = NULL;
	NODE* p, * next;
	float score;
	char buffer[S_SIZE];
	while (1)
	{
		printf("영화 제목(종료하려면 엔터를 입력하시오):");
		gets(buffer);
		if (buffer[0] == '\0')
			break;
		p = (NODE*)malloc(sizeof(NODE));
		strcpy(p->title, buffer);
		printf("영화 평점:");
		gets(buffer);
		score = atof(buffer);
		p->score = score;
		if (head == NULL)
			head = p;
		else
		{
			tail->link = p;
		}
		p->link = NULL;
		tail = p;
	}
	printf("====================================================\n");
	printf("제목 평점\n");
	printf("====================================================\n");

	p = head;
	while (p != NULL)
	{
		printf("%s %f\n",p ->title, p->score);
		p = p->link;
	}
	p = head;
	while (p != NULL)
	{
		next = p->link;
		free(p);
		p = next;
	}
	return 0;
}