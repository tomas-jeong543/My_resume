#include<stdio.h>

void FindSum(int Testscore[5][5], int width, int height);


int main(void) {

	//배열 및 성적의 대상과 과목이 무엇인지 알려주는 변수 초기화
	int TestScore[5][5];
	char* str = "철희";
	char* sub = "국어";

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			TestScore[i][j] = 0;
	}


	for (int i = 0; i < 4; i++) {
		
		switch (i) {

			//누구의 점수인지를 알려줌
			case 0:
				str = "철희";
				break;
			case 1:
				str = "철수";
				break;
			case 2:
				str = "영희";
				break;
			case 3:
				str = "영수";

		}
		
		
		for (int j = 0; j < 4; j++) {
			
			//어떤 과목의 점수인지를 알려줌
			switch (j) {

			case 0:
				sub = "국어";
				break;
			case 1:
				sub = "영어";
				break;
			case 2:
				sub = "수학";
				break;
			case 3:
				sub = "국사";
			
				//성적 입력 및 저장
				
			}
			//성적 입력 및 저장
			printf("%s 의 %s 성적 압력: ", str, sub);
			scanf_s("%d", &TestScore[i][j]);
		}
	}
	
	FindSum(TestScore, 5, 5);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			printf("%3d ", TestScore[i][j]);
		printf("\n");
	}

	return 0;

}

//과목별 총점과 학생병 총점을 더하는 함수
void FindSum(int Testscore[5][5], int width, int height) {

	int row = 0, col = 0;


	for (int i = 0; i < height -1; i++) {
		for (int j = 0; j < width -1; j++) {
			//학생별 총점의 합을 더해서 저장
			Testscore[i][width - 1] += Testscore[col][j];
			

			//과목별 총점의 합을 더해서 저장
			Testscore[height - 1][i] += Testscore[j][row];

		}
		row += 1, col += 1;
	}
	
	//학생의 점수의 총점을 이용해 전체 총점을 구한다.
	for (int i = 0; i < 4; i++)
		Testscore[height - 1][width - 1] += Testscore[height - 1][i];

}