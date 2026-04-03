#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 1000
int count = 0;

//이 탐색 기법은 탐색 기법보다는 이차 함수에서 극소 극대값을 찾는 방법과 유사하다
int ternary_search_peak(int arr[], int size) {
    //왼쪽과 오른쪽 값을 0과 배열의 길이로 설정함
    int left = 0, right = size - 1;
    //최대값을 찾지 못한 경우에 대해서 계속 탐색을 진행한다
    while (right - left > 2) {
        count++;
        //구간을 삼 등분한 왼쪽 점을 mid1로 지정
        int mid1 = left + (right - left) / 3;
        //구간을 삼 등분한 왼쪽 점을 mid2로 지정
        int mid2 = right - (right - left) / 3;
        //만약 왼쪽 구간에 가까운 삼등분 값이 오른쪽 구간의에 가까운 삼등분 값보다 작다면 왼쪽 구간의 시작점을 기존 왼쪽구간의 삼등분점 + 1로 위치를 옮긴다 
        if (arr[mid1] < arr[mid2]) left = mid1 + 1;
        //아닌 경우에는 반대로 한다
        else right = mid2 - 1;
        printf("left: %d  right: %d\n", left, right);
    }

    //극점 구간을 1,2로 좁히고 선형 탐색을 통해서 가장 큰 값이 존재하는 위치 정보를 획듯한다
    int max_idx = left;
    for (int i = left + 1; i <= right; i++) {
        if (arr[i] > arr[max_idx]) max_idx = i;
        count++;
    }

    return max_idx;
}

int main() {
    int arr[MAX_SIZE];
    srand(time(NULL));

    // Generate unimodal array with random peak position
    int peak = rand() % (MAX_SIZE - 2) + 1;
    for (int i = 0; i <= peak; i++) arr[i] = i;
    for (int i = peak + 1; i < MAX_SIZE; i++) arr[i] = arr[i - 1] - 1;

    int max_idx = ternary_search_peak(arr, MAX_SIZE);

    printf("Ternary Search (on unimodal array):\n");
    printf("Peak was generated at index %d with value %d\n", peak, arr[peak]);
    printf("Ternary search found peak at index %d with value %d\n", max_idx, arr[max_idx]);
    printf("count: %d\n", count);
    return 0;
}
