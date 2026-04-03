//오름차순으로 정렬하는 함수
void sortedupper(int* arr, int size)
{
	int temp;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}