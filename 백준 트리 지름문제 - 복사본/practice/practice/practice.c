#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
	int* list;
	int i, students;
	printf("학생 수를 입력하시오: ");
	scanf("%d", &students);
	list = (int* )malloc(students * sizeof(int));

	if (list == NULL)
	{
		printf("ERORR");
		return -1;
	}
	for (i = 0; i < students; i++) {
		printf("학생#%d 성적: ", i + 1);
		scanf("%d", &list[i]);
	}
	printf("\n\n");
	for (i = 0; i < students; i++)
		printf("학생 #%d성적: %d\n", i + 1, list[i]);
	free(list);
	return 0;
}