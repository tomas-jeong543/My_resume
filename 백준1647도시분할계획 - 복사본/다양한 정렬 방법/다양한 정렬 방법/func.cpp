#include"func.h"
#include<queue>
//성공
int partition_practice(string names[], int left, int right)
{

	string pivot = names[right];

	int i= left - 1;


	//주의 처음부터 모두 비교하면 안되고 왼쪽에서 오른쪽까지만 정렬이 필요하다
	for (int j = left; j < right; j++) {
		if (names[j].compare(pivot) < 0) {
			i += 1;
		string temp = names[i];
			
			names[i] = names[j];
			names[j] = temp;
		}
	}

	string temp2 = names[right];
	names[right] = names[i + 1];
	names[i + 1] = temp2;


	return i + 1;
}


void quick_sort_practice(string names[], int left, int right)
{
	if (left < right) 
	{
		int pivot = partition_practice(names, left, right);
		quick_sort_practice(names, left, pivot - 1);
		quick_sort_practice(names,  pivot + 1, right);
	}
}


//완성
void Radius_sort_practice(int arr[], int size)
{
	std::queue<int> bucket[10];

	int max = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	int ex = 1;

	while (max > ex) {

		for (int i = 0; i < size; i++) {
			int info = (arr[i] / ex) % 10;
			bucket[info].push(arr[i]);
		}

		int idx = 0;
		for (int i = 0; i < 10; i++) {
			while (!bucket[i].empty()) {
				arr[idx] = bucket[i].front();
				bucket[i].pop();
			}
		}


		ex *= 10;
	}

}