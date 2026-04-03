#include <stdio.h>
#include <stdlib.h>
#include<stack>
// Define Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new Node at the head
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new Node at the tail
void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a Node with a given key
void deleteNode(Node** head, int key) {
    Node* temp = *head, * prev = NULL;

    // In case the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }

    // Otherwise, search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If there is no such key in the list
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    //삭제하는 구문
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Function to search for a Node with a given key
bool searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



// Function to free the linked list
void freeList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    //low에서 high까지의 범위 안의 수에대해서만 위치 변경을 한다
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

int partition2(int arr[], int low, int high) {
    
    int middle = (low + high) / 2;
    int pivot = arr[middle];
    int i = low - 1;
    printf("pivot: %d\n", arr[middle]);
    //low에서 high까지의 범위 안의 수에대해서만 위치 변경을 한다
    for (int j = low; j < high + 1; j++) {
        if (j == middle) {
            continue;
        }
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
   }
    //가운데 정렬하는 경우에는 굳이 마지막에 바꿔주는 작업을 안해도 된다
    //int temp = arr[i + 1];
    //arr[i + 1] = arr[middle];
    //arr[middle] = temp;
    
    return i + 1;
}


// Iterative Quick Sort (with Stack)
void iterativeQuickSort(int arr[], int low, int high) {
    std::stack<int> stack;
    stack.push(low);
    stack.push(high);
    while (!stack.empty()) {
        high = stack.top(); stack.pop();
        low = stack.top(); stack.pop();
        printf("high: %d low: %d \n", high, low);;
        int pivot = partition2(arr, low, high);
        if (pivot - 1 > low) {
            stack.push(low);
            stack.push(pivot - 1);
        }
        if (pivot + 1 < high) {
            stack.push(pivot + 1);
            stack.push(high);
        }
        for (int i = 0; i < 8; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("\n");

    }
}

int main() {
    //Node* head = NULL;

    //// Data insertion
    //insertAtTail(&head, 10);
    //insertAtTail(&head, 20);
    //insertAtTail(&head, 30);
    //printList(head);

    //// Additional data insertion at the front
    //insertAtHead(&head, 5);
    //printList(head);

    //// Search operation
    //int tar_val = 20;
    //bool isFound = searchNode(head, tar_val);
    //if (isFound) {
    //    printf("Found Node: %d\n", tar_val);
    //}
    //else {
    //    printf("Node not found.\n");
    //}

    //// Delete operation
    //deleteNode(&head, 20);
    //printList(head);

    //// Free the linked list
    //freeList(&head);

    int arr[8] = {1, 8, 3, 4, 7, 6, 5, 2};
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");

    iterativeQuickSort(arr, 0, 7);
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
