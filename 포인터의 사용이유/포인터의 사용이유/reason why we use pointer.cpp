#include<iostream>

/*
* 포인터를 사용하는 이유는 자유 기억 장소의 자료를 다루거나 
클래스 맴버 자료나 맴버 함수 접근 시나 함수에 주소 전달시 많이 사용된다
*/
/*
* 메모리에서 지역변수는 스택에 코드는 코드 영역에 전역변수는 전역 공간 그리고 나머지는 자유 기억
공간 즉 힙에 저장이 된다 지역변수의 문제는 호출이 종료되면 지역 변수들이 버려진다는 것이다
그렇다고 전역변수를 사용하면 프로그래밍이 너무 복잡해지는 데 자료를 자유 기억 공간에 저장하면 이 두문제가 모두 해결이 된다
여기서 자유 기억 공간은 그냥 비어있는 다량의 메모리 집합으로 순서는 없지만 이 방의 주소를 이용해 자료를 저장할 수 있는 공간이다
*/

/*
자유 기억 공간에 메모리를 저장하는 것에 대한 이점은 바로 이 공산이 제거할 때까지 보관이 되고 이 포인터에 접근 가능한 함수만 자료애 접근이
가능해 캡슐화도 이루어 인터페이스 제공 및 대책 없는 방향으로 자료를 바꾸는 것을 예방할 수 있다
*/


int main()
{
	//new메소드를 통해 자유 기억 공간에 메모리 할당 가능하다
	//이 경우에서는 pPointer는 자유 기억 공간의 unsigned short 정수형 변수를 저장한다
	unsigned short int* pPointer;
	pPointer = new unsigned short int;
	//메모리 할당을 위해서는 메모리 누출을 막기 위해 수동으로 메모리 할당 해제 delete작업이 필요하다
	//만약 포인터가 선언된 함수가 반환시 포인터는 효력이 사라지는데 이 때 포인터에 할당된 메모리는 자동으로 해체되지 않는다
	//메모리 헤체 방법은 바로 delete사용 후 포인터에 널 대입하는 것이다
	delete pPointer;
	pPointer = 0;

	//포인터 할당과 해제 예제
	using std::cout;
	int Local_Variable = 5;
	int* Plocal = &Local_Variable;
	int* Pheap = new int;
	*Pheap = 7;
	cout << "local variable: " << Local_Variable << "\n";
	cout << "Plocal: " << *Plocal << "\n";
	cout << "Pheap: " << *Pheap << "\n";
	delete Pheap;
	Pheap = new int;
	*Pheap = 9;
	cout << "*Pheap: " << *Pheap << "\n";
	delete Pheap;

	//메모리 누출되는 다른 경우는 포인터를 삭제하기 전에 다른 값을 포인터에 넣으면 기존에 공간에 있는 값에 대해서는 접근이 불가능해져
	//메모리 누수가 일어난다
	//예제
	unsigned short int* aPointer = new unsigned short int;
	*aPointer = 74;
	//이 경우 74가 저장된 메모리 공간에 대한 메모리 누수가 발생한다
	//해결 문장
	delete aPointer;
	aPointer = new unsigned short int;
	*aPointer = 84;


	return 0;
}