#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void RemoveLinebuf()
{
	while (getchar() != '\n');
}

void RemoveBsn(char  * str)
{
	int len = strlen(str);
	str[len - 1] = 0;
}


void getinfoinLine(int** arr, char* line, int lineidx, int size)
{
	int startpoint1 = 0, startpoint2 = 0, digitnum = 0, ins;

	for (int i = 0; i < size; i++) {
		
		printf("startpoint1: %d, line %d %c \n", startpoint1, i, line[i]);

		while (line[startpoint1] > 47 && line[startpoint1] < 58) {
				digitnum += 1;
				startpoint1 += 1;
				printf("startpoint1: %d\n", startpoint1);
			}

		while (line[startpoint2] > 47 && line[startpoint2] < 58) {
			

			ins = pow(10, digitnum - 1) * atoi(line[startpoint2]);
			printf("ins: %d\n", ins);
			arr[lineidx][i] += ins;
			startpoint2 += 1;
			
		}
	
		digitnum = 0;
	}

}