#pragma once
class MyArray {
private:
    int* data;
    size_t size;

public:
    MyArray(size_t s);

    MyArray(const MyArray& other);
    MyArray(MyArray&& other) noexcept;


    MyArray& operator=(const MyArray& other);
    MyArray& operator=(MyArray&& other) noexcept;
    ~MyArray();

    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    void setValue(size_t index, int value);

    void printValue();
};


