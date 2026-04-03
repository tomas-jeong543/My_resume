/*/#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



int main(void) {

	FILE* src0 = fopen("src.bin" , "wb");
	FILE* des = fopen("dst6.bin", "wb");
	char buf[1];
	int readCnt;
	char buf2[6] = { 48, 49, 48, 49, 48 , 10};

	fwrite((void*)buf2, 1, sizeof(buf2), src0);

	fclose(src0);

	FILE* src = fopen("src.bin", "rb");
	for(int  i = 0; i < 6; i++)
		printf("%c \n", fgetc(src));

	if (src == NULL || des == NULL) {
		puts("파일 오픈 실패!");
		return -1;
	}

	while (1) {
		
		readCnt = fread((void*)buf, sizeof(char), 6, src);
		
		printf("count: %d \n", readCnt);

		if (readCnt < sizeof(buf))
		{
			if (feof(src) != 0)
			{
				fwrite((void*)buf, 1, readCnt, des);
				puts("파일복사 완료");
				break;
			}
			else
				puts("파일복사 실패");

			break;
		}
	
		fwrite((void*)buf, 1, readCnt, des);
	}
	
	fclose(src);
	fclose(des);
	return 0;
}*/