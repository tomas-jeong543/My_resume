#include<iostream>
// 변수형의 주의점 int는 16비트인지 32비트인지에 따라서 범위의 차이가 있을 수 있다
//하지만 long int를 사용하면 무조건 c언어 에서의 int의 범위와 같다
int main()
{
	// 나열형 상수로 값을 초기화하지 않으면 0부터 시작해 1씩 증가하는 값을 갖는다
	//그리고 앞의 값이 100이고 뒤의 값이 500인 사이값의 숫자 값은 앞의 값 + 1인 101이다
	enum Days {Sunday, Monday, Tuseday, Wensday, Thursday, 
		Friday, Saturday};

	Days today;
	today = Monday;

	if (today == Sunday || today == Saturday)
		std::cout << "\nGotta' love the weekends\n";
	else
		std::cout << "\n Back to Work";

	return 0;
}