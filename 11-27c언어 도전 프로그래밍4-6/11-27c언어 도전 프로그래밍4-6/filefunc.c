#include "Phonenuminfo.h"
#include<stdio.h>

PhonInfo* Load(FILE *  fp, int *sizeptr) {

	PhonInfo* phone;
	char str[1];
	int size = atoi(fgets(str,sizeof(str), fp));
	*sizeptr = size;

	printf("%d\n", size);

	if (size == 0) {
		 phone = (PhonInfo*)malloc(sizeof(PhonInfo));
		 *sizeptr = 0;
		 return phone;
	}


	phone = (PhonInfo*)malloc(sizeof(PhonInfo) * size);

	for (int i = 0; i < size; i++) {
		if (fread(&phone[i], sizeof(PhonInfo), 1, fp) != 1) {
			puts("데이터 불러오는 과정에서 오류 발생");
		 }

	}


	return phone;
}

void Save(FILE* fp,PhonInfo * phone,  int *size) {
	fseek(fp, 0, SEEK_SET);
	printf("%d\n", *size - 1);
	fputc(*size - 1, fp);

	for (int i = 0; i < *size - 1; i++) {
		if (fwrite(&phone[i], sizeof(PhonInfo), 1, fp) != 1) {
			puts("데이터 저장하는 과정에서 오류 발생");
		}
	}
	fseek(fp, 0, SEEK_SET);
	int ch = fgetc(fp);
	printf("%d\n", ch);
}
