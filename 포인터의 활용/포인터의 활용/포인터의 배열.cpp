#include<stdio.h>
int global_var = 50;
void call_by_value(int* p)
{
	*p = global_var;
}
void call_by_reference(int** p)
{
	*p = &global_var;
}
int main(void)
{
	int local_var = 10;
	int* ptr1, * ptr2;

	ptr1 = &local_var;
	ptr2 = &local_var;
	printf("Before: *value = %d, *refer = %d\n", *ptr1, *ptr2);
	call_by_value(ptr1);
	call_by_reference(&ptr2);
	printf("After: *value = %d, *refer = %d\n", *ptr1, *ptr2);
	return 0;
}