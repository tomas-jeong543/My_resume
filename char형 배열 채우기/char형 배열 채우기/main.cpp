#include<iostream>

using namespace std;

int main()
{
	char buffer[80];
	cout << "Enter the String: ";
	cin .get(buffer, 79);
	cout << "here's the buffer: " << buffer << endl;


	//간단한 strncpy 예제 길이의 제한 두고  뒤의 널문자를 고려한 사이즈 측정 
	
	const int Max_Length = 80;
	char String1[] = "No man is an island";
	char String2[Max_Length + 1];
	
	strncpy_s(String2, String1, Max_Length);

	cout << "String1: " << String1 << endl;
	cout << "String2: " << String2 << endl;
	return 0;
}