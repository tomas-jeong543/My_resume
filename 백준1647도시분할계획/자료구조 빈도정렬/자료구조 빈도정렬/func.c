

int* Sorted_Upper(int* num, int size) {

	int tmp;

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (*(num + i) < *(num + j)) {
				tmp = *(num + i);
				*(num + i) = *(num + j);
				*(num + j) = tmp;
			}
		}
	}

	return num;
}