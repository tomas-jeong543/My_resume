#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <time.h>

void printArray(int arr[], int n, bool opt = false) {
    if (opt) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Radix Sort (with Queue)
void radixSort(int arr[], int n) {
    std::queue<int> buckets[10];//지금 데이터가 어디 들어가는 지 확인이 필요하다
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    int exp = 1;
    while (maxVal / exp > 0) { //가장 큰 자리수
        for (int i = 0; i < n; i++) {
            int bucketIdx = (arr[i] / exp) % 10; //현재 value가 어디 버킷에 들어가야 되는지 확인 
            buckets[bucketIdx].push(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!buckets[i].empty()) {
                arr[index++] = buckets[i].front();
                buckets[i].pop();
            }
        }
        exp *= 10;
    }
}

// Iterative Quick Sort (with Stack)
void iterativeQuickSort(int arr[], int low, int high) {
    std::stack<int> stack;

    stack.push(low);
    stack.push(high);
    //while문 이용해 정렬 
    while (!stack.empty()) {
        high = stack.top(); stack.pop();
        low = stack.top(); stack.pop();
        int pivot = partition(arr, low, high);
        if (pivot - 1 > low) {
            stack.push(low);
            stack.push(pivot - 1);
        }
        if (pivot + 1 < high) {
            stack.push(pivot + 1);
            stack.push(high);
        }
    }
}

int main() {

    const int SIZE = 50;
    int originalArr[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        originalArr[i] = rand() % 1000;
    }
    int arr[SIZE];
    clock_t start, end;
    bool print_opt = false;
    const char* time_unit = "ms";
    double time_scaler;

    if (strcmp(time_unit, "ns") == 0)
        time_scaler = 1000000000.0;
    else if (strcmp(time_unit, "ms") == 0)
        time_scaler = 1000.0;
    else
        time_scaler = 1.0;

    printf("Original Array:\n");
    printArray(originalArr, SIZE);

    copyArray(originalArr, arr, SIZE);
    start = clock();
    bubbleSort(arr, SIZE);

    end = clock();
    printf("\nBubble Sort:\n");
    printArray(arr, SIZE, print_opt);
    printf("Execution Time: %lf %s\n", (double)(end - start) * time_scaler / CLOCKS_PER_SEC, time_unit);

   /* copyArray(originalArr, arr, SIZE);
    start = clock();
    selectionSort(arr, SIZE);
    end = clock();
    printf("\nSelection Sort:\n");
    printArray(arr, SIZE, print_opt);
    printf("Execution Time: %lf %s\n", (double)(end - start) * time_scaler / CLOCKS_PER_SEC, time_unit);

    copyArray(originalArr, arr, SIZE);
    start = clock();
    insertionSort(arr, SIZE);
    end = clock();
    printf("\nInsertion Sort:\n");
    printArray(arr, SIZE, print_opt);
    printf("Execution Time: %lf %s\n", (double)(end - start) * time_scaler / CLOCKS_PER_SEC, time_unit);

    copyArray(originalArr, arr, SIZE);
    start = clock();
    mergeSort(arr, 0, SIZE - 1);
    end = clock();
    printf("\nMerge Sort:\n");
    printArray(arr, SIZE, print_opt);
    printf("Execution Time: %lf %s\n", (double)(end - start) * time_scaler / CLOCKS_PER_SEC, time_unit);

    copyArray(originalArr, arr, SIZE);
    start = clock();
    quickSort(arr, 0, SIZE - 1);
    end = clock();
    printf("\nQuick Sort:\n");
    printArray(arr, SIZE, print_opt);
    printf("Execution Time: %lf %s\n", (double)(end - start) * time_scaler / CLOCKS_PER_SEC, time_unit);

    copyArray(originalArr, arr, SIZE);
    start = clock();
    radixSort(arr, SIZE);
    end = clock();
    printf("\nRadix Sort:\n");
    printArray(arr, SIZE, print_opt);
    printf("Execution Time: %lf %s\n", (double)(end - start) * time_scaler / CLOCKS_PER_SEC, time_unit);

    copyArray(originalArr, arr, SIZE);
    start = clock();
    iterativeQuickSort(arr, 0, SIZE - 1);
    end = clock();
    printf("\nIterative Quick Sort:\n");
    printArray(arr, SIZE, print_opt);
    printf("Execution Time: %lf %s\n", (double)(end - start) * time_scaler / CLOCKS_PER_SEC, time_unit);*/

    return 0;
}