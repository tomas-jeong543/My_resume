#pragma once
#include<memory>
#include"ArrayData.h"
class ArrayDataSmart :public ArrayData
{
private:
    unique_ptr<double[]> backdata;
    int usedB;
public:
    ArrayDataSmart();
    ArrayDataSmart(const ArrayDataSmart& arr);
    ArrayDataSmart(ArrayDataSmart&& arr)noexcept;
    ArrayDataSmart(const int& capcity, const int& used = 0);
    ~ArrayDataSmart();
    void backup();
    void restore();
    ArrayDataSmart& operator=(const ArrayDataSmart& rhs);
    ArrayDataSmart& operator=(const ArrayDataSmart&& rhs)noexcept;
};

