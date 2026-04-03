#include<iostream>
//switch문을 쓸 때 주의점 늘 break문을 빼먹지 말고 일부러 빼는 경우에는 주석으로 이유룰 설명해야 한다
//그리고 늘 default를 생성해야 한다

//순환마다 변수 수정해야 하면 for문 아니면 while문 사용을 권고한다
int menu();
void DoTask(int);

using namespace std;

int main()
{
	bool exit = false;
	for (;;)
	{
		int choice = menu();
		switch (choice)
		{
		case(1):
			DoTask(1);
			break;
		case(2):
			DoTask(2);
			break;
		case(3):
			DoTask(3);
			break;
		case(4):
			break;
		case(5):
			exit = true;
			break;
		default:
			cout << "Please select again! \n";
			break;
		}
		if (exit)
			break;
	}
	return 0;
}