#include<iostream>

// 기호 상수 constant 주로 define을 이용한다
//전처리계가 이 나이를 23으로 바꾸기 때문에 컴파일러는 이 문장을 만나지 않는다 
#define age = 23;
// 더 좋은 방법은 const를 이용해 선언하면 프로그램 내내 그 값이 유지가 된다
//가장 큰 이점은 상수정의로 형을 가질 수 있고 그 형에 따라 사용할 수 있게 한다는 것
const int number = 20;
int main()
{
	//for문을 이용해서 아스키 코드 값을 출력했다
	for (int i = 32; i < 128; i++)
	{
		std::cout << (char)i ;
	}
	// 이스케이프 문자 예시 \000 8진법 표시 \xhhh 16진법 표시 \\역시선 그 자체
	// \v 수직 탭 \r캐리지 리턴


}