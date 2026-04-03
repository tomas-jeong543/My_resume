//벡터 매칭 스페셜 저지
//시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
//2 초	512 MB	14299	5335	3897	38.083 %
//문제
//평면 상에 N개의 점이 찍혀있고, 그 점을 집합 P라고 하자.집합 P의 벡터 매칭은 벡터의 집합인데, 모든 벡터는 집합 P의 한 점에서 시작해서, 또 다른 점에서 끝나는 벡터의 집합이다.
// 또, P에 속하는 모든 점은 한 번씩 쓰여야 한다.
//
//벡터 매칭에 있는 벡터의 개수는 P에 있는 점의 절반이다.
//
//평면 상의 점이 주어졌을 때, 집합 P의 벡터 매칭에 있는 벡터의 합의 길이의 최솟값을 출력하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 테스트 케이스의 개수 T가 주어진다.각 테스트 케이스는 다음과 같이 구성되어있다.
//
//테스트 케이스의 첫째 줄에 점의 개수 N이 주어진다.N은 짝수이다.둘째 줄부터 N개의 줄에 점의 좌표가 주어진다.N은 20보다 작거나 같은 자연수이고, 좌표는 절댓값이 100, 000보다 작거나 같은 정수다.
// 모든 점은 서로 다르다.
//
//출력
//각 테스트 케이스마다 정답을 출력한다.절대 / 상대 오차는 10 - 6까지 허용한다.

#include<iostream>
#include<cmath>
#include<deque>
using namespace std;

class Point {

public:
	Point(double xpos, double ypos) {
		this->xpos = xpos;
		this->ypos = ypos;
	}
	double xpos;
	double ypos;

	void show()const {
		cout << "xpos:" << xpos << " ypos: " << ypos << endl;
	}
};

double Caldis(double pos1x, double pos1y, double pos2x, double pos2y) {

	return sqrt((pos1x - pos2x) * (pos1x - pos2x) + (pos1y - pos2y) * (pos1y - pos2y));
}



int main()
{
	int Tnum;
	cout << "테스트 케이스 수: ";
	cin >> Tnum;
	cin.ignore();

	for (int i = 0; i < Tnum; i++) {
		deque<Point> points;
		int pointnum;
		double total_dis = 0.0;
		do {
			cout << "점의 수: ";
			cin >> pointnum;
			cin.ignore();
		} while (pointnum % 2 != 0 || pointnum <= 0);
	
		
		for (int i = 0; i < pointnum; i++) {
			double xpos, ypos;
			cout << "점의 좌표 입력: ";
			cin >> xpos >> ypos;
			double check = abs(xpos) + abs(ypos);
			Point ins(xpos, ypos);
			points.push_back(ins);
		}

		for (int i = 0; i < pointnum - 1; i++) {
			for (int j = 0; j < pointnum - i - 1; j++) {
				if (Caldis(points[j].xpos, points[j].ypos, 0, 0) < Caldis(points[j + 1].xpos, points[j + 1].ypos, 0, 0)) {
					Point ins(0, 0);
					ins = points[j];
					points[j] = points[j + 1];
					points[j + 1] = ins;
				}
			}
		}

		while (!points.empty()) {
			
			double dis = -1;
			Point ins2(0, 0);
			Point ins1(0, 0);
			ins1 = points.front();
			points.pop_front();
			ins2 = points.front();

			for (Point p : points) {
				if ( dis == -1) {
					dis = Caldis(p.xpos + ins1.xpos, p.ypos + ins1.ypos, 0, 0);
					ins2 = p;
				}
				else {
					double insdis = Caldis(p.xpos + ins1.xpos, p.ypos + ins1.ypos, 0, 0);
					if (insdis < dis) {
						dis = insdis;
						ins2 = p;
					}
				}
			}
			
			while (points.front().xpos != ins2.xpos || points.front().ypos != ins2.ypos) {
				points.push_back(points.front());
				points.pop_front();
			}

			ins1.show();
			ins2.show();
			cout << "dis: " << dis << endl;
			points.pop_front();
			total_dis += dis;
		}

		cout << "total distance: " << total_dis << endl;
	}
	return 0;
}