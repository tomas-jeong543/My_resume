#pragma once

template<typename T, int MAX>
class Stack
{
private:
	T items[MAX];
	int top;
public:
	static inline int count;
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const T& item);
	bool pop(T& item);
};


//이런 식으로 정적인 변수를 초기화 할 수 있다
template<typename T, int MAX>
int Stack<T, MAX>::count = 0;

template<typename T, int MAX>
inline Stack<T, MAX>::Stack()
{
	top = 0;
}

template<typename T, int MAX>
inline bool Stack<T, MAX>::isempty() const
{
	return top == 0;
}
template<typename T, int MAX>
inline bool Stack<T, MAX>::isfull() const
{
	return top == MAX;
}

template<typename T, int MAX>
inline bool Stack<T, MAX>::push(const T& item)
{
	if (top < MAX) {
		items[top++] = item;
		return true;
	}
	else {
		return false;
	}
}

template<typename T, int MAX>
inline bool Stack<T, MAX>::pop(T& item)
{
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else {
		return true;
	}
}
