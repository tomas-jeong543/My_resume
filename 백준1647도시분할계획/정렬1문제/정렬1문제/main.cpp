#include<iostream>

using namespace std;

typedef struct{
	int stdid;
	int coding_score;
	int algorithm_score;

}Std;


void Partition(Std arr[], int left ,int middle,int right, int opt)
{
	int lsize = middle - left + 1;
	int rsize = right - middle;

	Std* L = new Std[lsize];
	Std* R = new Std[rsize];
	if (L == nullptr || R == nullptr) {
		cerr << "memory error" << endl;
		return;
	}

	int i = 0, j = 0, k = left;
	for (int i = 0; i < lsize; i++) { L[i] = arr[left + i]; }
	for (int i = 0; i < rsize; i++) { R[i] = arr[middle + i + 1]; }

	if (opt == 0) {
		while (i < lsize && j < rsize) {
			if (L[i].stdid > R[j].stdid) { arr[k++] = R[j++]; }
			else { arr[k++] = L[i++]; }
		}
	}
	else if (opt == 1) {

		while (i < lsize && j < rsize) {
			if (L[i].algorithm_score < R[j].algorithm_score) { arr[k++] = R[j++]; }
			else { arr[k++] = L[i++]; }
		}
	}
	else {

		while (i < lsize && j < rsize) {
			if (L[i].coding_score < R[j].coding_score) { arr[k++] = R[j++]; }
			else { arr[k++] = L[i++]; }
		}
	}

	while (i < lsize) { arr[k++] = L[i++]; }
	while (j < rsize) { arr[k++] = R[j++]; }

	delete[] L;
	delete[] R;
}

void Merge(Std arr[], int left, int right, int opt)
{
	int middle = left + (right - left) / 2;

	if (left < right) {
		Merge(arr,left, middle, opt);
		Merge(arr,middle + 1, right, opt);
		Partition(arr, left,middle, right, opt);
		
	}
}

int main()
{
	const int SIZE = 6;
	int id = 10000;
	Std* stdarr = new Std[SIZE];

	for (int i = 0; i < SIZE; i++) {
		stdarr[i].stdid = id + i;
	}

	stdarr[0].coding_score = 90;
	stdarr[1].coding_score = 90;
	stdarr[2].coding_score = 95;
	stdarr[3].coding_score = 80;
	stdarr[4].coding_score = 90;
	stdarr[5].coding_score = 95;
	
	stdarr[0].algorithm_score = 85;
	stdarr[1].algorithm_score = 90;
	stdarr[2].algorithm_score = 80;
	stdarr[3].algorithm_score = 70;
	stdarr[4].algorithm_score = 85;
	stdarr[5].algorithm_score = 90;
	
	for (int i = 0; i < 3; i++) {
		Merge(stdarr, 0, SIZE - 1, i);
	}

	for (int i = 0; i < SIZE; i++) {
		cout << "학생 번호 " << stdarr[i].stdid << " 학생 알고리즘 점수: " << stdarr[i].algorithm_score << " 학생 코딩 점수: " << stdarr[i].coding_score << endl;
	}
	
}