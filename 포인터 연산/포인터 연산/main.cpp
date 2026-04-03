#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctype.h>
#include<string.h>
bool Get_Word(char* theString, char* word , int&wordOffset);

int main()
{
	const int Buffer_Size = 255;
	char buffer[Buffer_Size + 1];
	char word[Buffer_Size + 1];
	int Word_Offset = 0;

	std::cout << "Enter a string: ";
	std::cin.getline(buffer, Buffer_Size);

	while (Get_Word(buffer, word, Word_Offset) ){
		std::cout << "Got this word: " << word << std::endl;
	}

	return 0;
}


bool Get_Word(char* theString, char* word, int&wordOffset)
{
	//문자열 끝 판단
	if (!theString[wordOffset])
		return false;

	char* p1, * p2;
	p1 = p2 = theString + wordOffset;
	//앞에 공백문자 없애기
	for (int i = 0; i < (int)strlen(p1) && !isalnum(p1[0]); i++)
		p1++;

	std::cout << "check: " << p1[0] << "  ";

	//단어를 가지고 있는지 확인 가지고 있지 않으면 거짓반환
	if (!isalnum(p1[0]))
		return false;

	//두 포인터 다 다음 단어의 시작을 나타낸다
	p2 = p1;

	//p2는 단어의 끝을 나타낸다
	while (isalnum(p2[0]))
		p2++;

	//단어의 길이 측정 및 단어를 버퍼에 넣는다
	int len = int(p2 - p1);
	strncpy(word, p1, len);
	//널 문자 넣기
	word[len] = '\0';

	//다음 단어의 시작을 찾아 wordOffset에 저장한다
	for (int j = int(p2 - theString); j < (int)strlen(theString) && !isalnum(p2[0]); j++)
	{
		p2++;
	}

	wordOffset = int(p2 - theString);

	return true;

}