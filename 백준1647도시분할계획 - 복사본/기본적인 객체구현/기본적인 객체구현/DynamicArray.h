#pragma once
class DynamicArray
{
private:
	int* arr;
	int size;
	int capcity;
public:
	DynamicArray(int cap, int size = 0);
	~DynamicArray();
	DynamicArray(const DynamicArray& rhs);
	DynamicArray(DynamicArray&& rhs)noexcept;
	DynamicArray& operator=(const DynamicArray& rhs);
	DynamicArray& operator=(DynamicArray && rhs)noexcept;
	int& operator[](size_t num);
	const int& operator[](size_t num) const;
	
	void swap(DynamicArray& first, DynamicArray& second) noexcept;
	int sizeinfo() const{
		return capcity;
	}

};

