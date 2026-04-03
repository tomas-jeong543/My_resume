/*문제
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다.섬의 개수를 세는 프로그램을 작성하시오.



한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다.지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다.w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 섬의 개수를 출력한다.*/

//처음으로 c++을 이용해서 푼 문제 나름 흥미로웠다 결국 메모리 할당 및 해제하는 것이 가장 까다로웠다 확실히 자유도가 높은 만큼
//더 많은 공부와 학습으로 꼼꼼히 메모리 관리를 해야된다는 것을 느꼈다

#include<iostream>
#include"func.h"
#include<deque>
#include<string>
#include<sstream>
using namespace std;

int** Makearr(int h, int w);


int main()
{
	int w, h;

	while (true)
	{
		cin >> w >> h;
		cin.ignore();
		if (w == 0 && h == 0) 
			break;

		int** mapinfo = Makearr(h, w);

		stringstream buf;
		string str_info;
		
	
		for (int i = 0; i < h; i++) {
			stringstream buf;
			getline(cin, str_info);
			buf.str(str_info);
			for (int j = 0; j < w; j++) {
				buf >> mapinfo[i][j];
			}
		}
		
		cout << "섬의 개수: " << Find_iland_NUm(w, h,mapinfo);


		//메모리 할당 해제
		delete[] mapinfo;

	}
	return 0;
}


int** Makearr(int h, int w)
{
	int** arr = new int* [h];
	if (arr == nullptr) {
		cout << "메모리 할당 중 오류 발생\n";
		return NULL;
	}


	for (int i = 0; i < h; i++) {
		*(arr + i) = new int[w];
		

		if (*(arr + i) == nullptr) {
			cout << "메모리 할당 중 오류 발생\n";
			return NULL;
		}
	}
	return arr;
}