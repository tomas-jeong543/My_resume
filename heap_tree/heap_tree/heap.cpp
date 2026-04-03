#include <stdio.h>
//배열로 힙을 만드는 방법

//초기화
#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;
//

//부모, 왼쪽 자식, 오른쪽 자식 접근하는 함수 선언 이때 이 경우에는 부모는 인덱스 1부터 시작한다고 보면 된다
int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

//두 수의 값을 바꾸는 swap함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//삽입함수
void insert(int value) {
    //배열의 공간을 heap[1]부터 할당하기 때문에 전위 증가를 시킨다
    int i = ++heapSize;
    //공간에 변수 할당
    heap[i] = value;

    //아래에서 부터 heap up을 시킨다 부모와 비교해 더 크면 swap함수를 이용해 두 값을 바꾸고 그 부모의 위치로 이동한다
    while (i > 1 && heap[parent(i)] < heap[i]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
}

int deleteMax() {
    //요소가 없는 경우에 대한 예외처리
    if (heapSize == 0) return -1;

    //일단 최상단에 있는 루트노드 값을 이용해 최대값을 얻는다
    int max = heap[1];
    //최상단의 노드를 가장 아래에 존재하는 노드로 교체한다.
    heap[1] = heap[heapSize--];

    int i = 1;

    //bubble down과정이다.
    while (1) {


        int l = left(i);
        int r = right(i);
        int largest = i;
        //왼쪽 자식과 오른쪽 자식 부모 중 가장 큰 값의 위치를 largerst 변수에 저장한다 이건 인덱스가 1부터 시작하는 경우에 대해서의 처리다
        if (l <= heapSize && heap[l] > heap[largest]) largest = l;
        if (r <= heapSize && heap[r] > heap[largest]) largest = r;
        //만약 바뀌지 않았다면 while문 탈출
        if (largest == i) break;
        //바뀌었다면 교환하고 교환된 점에 대해서 다시 bubble down 과정을 거친다. 이 과정을 계속 거치면 heap구조를 유지할 수 있게 된다.
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
    //최대값을 반환한다.
    return max;
}
//레벨 별로 힙구조를 출력하는 흥미로운 함수
void printHeapByLevel() {
    int level = 0;
    int count = 0;
    int nextLevelCount = 1;

    printf("Heap by Level:\n");
    for (int i = 1; i <= heapSize; i++) {
        if (count == 0) {
            printf("Level %d: ", level);
        }

        printf("%d ", heap[i]);
        count++;

        if (count == nextLevelCount) {
            printf("\n");
            level++;
            count = 0;
            nextLevelCount *= 2;
        }
    }

    if (count != 0) {
        printf("\n");
    }
}

void heapify(int i) { // bubble down approach 방식으로 힙화를 하는 합수 재귀 구조를 이용한다
    //자식과 비교해 힙 구조를 충족하는 지 비교하고 충족하면 함수를 종료하고 충족하지 않는다면 자식과 부모를 교환하고
    //교환된 부모에 대해서 다시 힙 관계를 충족하는지를 확인한다.
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l <= heapSize && heap[l] > heap[largest]) largest = l;
    if (r <= heapSize && heap[r] > heap[largest]) largest = r;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

void buildHeap() { // print intermediate results 힙화하는 중간 과정마다 힙 구조의 변화를 보기 위해서 호출하는 함수
    printf("Start building heap (heapify from bottom-up):\n");
    //가장 하위레벨에 있는 노드 위의 레벨의 점 부터 진행한다. 그 아래의 점들은 자식이 없기 때문이다. 즉 가장 마지막 부모 부터 진행한다는 의미이다.
    for (int i = parent(heapSize); i >= 1; i--) {
        printf("\nHeapify at index %d (value = %d):\n", i, heap[i]);
        heapify(i);
        printHeapByLevel();
    }

    printf("\n Finished building heap.\n");
}

void printHeap() { // print in array form
    printf("Heap: ");
    for (int i = 1; i <= heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(30);
    insert(20);
    insert(5);
    insert(40);

    printHeapByLevel();

    printf("Deleted max: %d\n", deleteMax());
    printf("Deleted max: %d\n", deleteMax());
    printf("Deleted max: %d\n", deleteMax());
    printf("Deleted max: %d\n", deleteMax());
    printHeapByLevel();

    heap[1] = 15;
    heap[2] = 8;
    heap[3] = 10;
    heap[4] = 2;
    heap[5] = 25;
    heapSize = 5;

    printf("\nBefore buildHeap:\n");
    printHeapByLevel();

    buildHeap();

    printf("After buildHeap:\n");
    printHeapByLevel();

    return 0;
}
