#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000

int comparisons = 0;

//선형 탐색
int linear_search(int arr[], int n, int key) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

//이진 탐색
int binary_search(int arr[], int left, int right, int key) {
    comparisons = 0;
    //왼쪽 끝값이 오른쪽 범위 이하인 경우에 대해서 계속 반복한다
    while (left <= right) {
        comparisons++;
        //이 부분은 int ovwrflow를 막기 위해서 이렇게 설정함
        int mid = left + (right - left) / 2;
        //발견시 반환
        if (arr[mid] == key) {
            return mid;
        }//찾으려는 값보다 가운데 값이 작은 경우 왼쪽 범위의 이동
        else if (arr[mid] < key) {
            left = mid + 1;
        }//반대의 경우 오른쪽 범위의 이동
        else {
            right = mid - 1;
        }
    }
    //못 찾은 경우에는 -1을 반환한다
    return -1;
}

//배열이 정렬이 되어있고 찾으려는 값이 하나밖에 없다고 가정한다
int jump_search(int arr[], int n, int key) {
    comparisons = 0;
    //점프의 간격은 전체 배열의 크기가 n 일때 root(n)의 정수 부분이다
    int step = sqrt(n);
    //이전 위치 정보를 저장하는 prev를 초기화한다
    int prev = 0;
    //배열의 크기를 벗어나지 않는 동안 점프한 요소에 대해서 목표값과 대소 비교를 한다
    while (arr[(step < n ? step : n) - 1] < key) {

        comparisons++;
        //이전 점과 현재 점 정보의 갱신
        prev = step;
        step += sqrt(n);
        //만얃 현재 점이 배열 크기의 끝에 도달한 경우에는 찾으려는 값이 존재하지 않는다는 의미임으로 -1을 반환합니다
        if (prev >= n) {
            return -1;
        }
    }
    //만약 찾으려는 요소가 있을 것으로 기대되는 구간 정보를 얻었다면 prev부터 시작해 1씩 증가시키면서 찾으려는 요소와 계속 비교를 해준다.
    while (arr[prev] < key) {
        comparisons++;
        prev++;
        //만약 주어진 범위를 다 선형탐색해도 존재하지 않는다면 -1반환
        if (prev == step || prev >= n) {
            return -1;
        }
    }
    comparisons++;
    //만약 찾으려는 요소가 존재하면 그 위치인 prev를 반환하고 아닌 경우에는 -1을 반환한다 이 때 여기까지 흐름도가 진행되었다는 의미는 arr[prev] >= key라는 의미기도 하다
    return (arr[prev] == key) ? prev : -1;
}

//정렬된 상태 + 데이터의 uniform(균등한) 분포한 상황을 가정한다
int interpolation_search(int arr[], int n, int key) {
    comparisons = 0;
    int low = 0, high = n - 1;
    //왼쪽 위치값이 오른쪽 위치값보다 작거나 같고 찾으려는 요소가 그 둘 사이에 존재할 때 탐색을 계속한다
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        comparisons++;
        //위치 binary-search에서의 mid값을 설정한다
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);
        //현재 위치의 값과 내가 찾으려는 값의 비교를 통해서 범위를 바꾼다
        if (arr[pos] == key) {
            return pos;
        }
        if (arr[pos] < key) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }
    //못 찾은 경우 -1반환
    return -1;
}

//지수형 탐색 역시 정렬된 상태를 의미한다
int exponential_search(int arr[], int n, int key) {
    comparisons = 0;
    //첫 번째 요소가 내가 찾는 값인 경우
    if (arr[0] == key) {
        comparisons++;
        return 0;
    }
    int i = 1;
    //지수 탐색의 범위를 1,2,4,8,16,32,64 .... 이런 식으로 계속 *2를 해준다
    while (i < n && arr[i] <= key) {
        comparisons++;
        i *= 2;
    }
    int left = i / 2;
    //이 부분은 꽤나 주의해야 하는 데 *2한 값이 배열의 크기를 초과할 수 있음으로 크기를 초과한 경우에 대한 삼항 연산자의 대처가 필요하다
    int right = (i < n) ? i : n - 1;
    //주어진 범위에서 이진 탐색을 진행한다
    int result = binary_search(arr, left, right, key);
    comparisons += comparisons;
    return result;
}

void print_result(int result) {
    if (result == -1) printf("Not found\n");
    else printf("Found at index %d\n", result);
}

int main() {
    //난수 발생 및 배열 선언
    srand(time(NULL));
    int arr[MAX_SIZE];
    arr[0] = rand() % 5;
    //이렇게 초기화 시키면 당연히 interpolation search가 유리하다
  /*  for (int i = 1; i < MAX_SIZE; i++) {
        arr[i] = arr[i - 1] + 1 + rand() % 5;
    }*/

    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = MAX_SIZE - i ;
    }


    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = MAX_SIZE - i;
    }

    for (int i = 0; i < MAX_SIZE / 3; i++) {
        int tmp = arr[i];
        arr[i] = arr[MAX_SIZE - i * 2];
        arr[MAX_SIZE - i * 2] = tmp;
    }

    int key = arr[rand() % MAX_SIZE];

    printf("Search key: %d\n\n", key);

    int result = linear_search(arr, MAX_SIZE, key);
    printf("Linear Search: ");
    print_result(result);
    printf("Comparisons: %d\n\n", comparisons);

    result = binary_search(arr, 0, MAX_SIZE - 1, key);
    printf("Binary Search: ");
    print_result(result);
    printf("Comparisons: %d\n\n", comparisons);

    result = jump_search(arr, MAX_SIZE, key);
    printf("Jump Search: ");
    print_result(result);
    printf("Comparisons: %d\n\n", comparisons);

    result = interpolation_search(arr, MAX_SIZE, key);
    printf("Interpolation Search: ");
    print_result(result);
    printf("Comparisons: %d\n\n", comparisons);

    result = exponential_search(arr, MAX_SIZE, key);
    printf("Exponential Search: ");
    print_result(result);
    printf("Comparisons: %d\n\n", comparisons);


    return 0;
}