#include <stdio.h>
#include <stdlib.h>

// Call by value - int
void modifyInt_1(int a) {
    a = 10;
}

// Call by reference - int
void modifyInt_2(int* a) {
    *a = 10;
}

// Define Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Call by value - Node
void modifyHead_1(Node* head) {
    Node newNode;
    head = &newNode;

    int tmp = 0;
}


void Modify_value(Node* head) {
    (*head).data = 1;
}

// Call by reference - Node
void modifyHead_2(Node** head) {    // Node** head == &head
    //이런식으로 코딩하면 메모리 할당 해제가 잘 되지 않음으로 이러지 말고 mallcoc으로 메모리 할당하는 것이 합리적이다
    Node tmp;
    *head = &tmp;
    (&tmp)->data = 1;

}

int main() {

    int a = 5;                                                                                                                                  
    printf("Initial value of a is %d\n", a);

    modifyInt_1(a);
    printf("After modifyint_1 a is %d\n", a);

    modifyInt_2(&a);
    printf("After modifyint_2 a is %d\n", a);
    printf("\n");
    printf("\n");

    Node* head_1 = NULL;
   
    Node* head_2 = NULL;

    Node head3;

    modifyHead_1(head_1);
    printf("%p\n", head_1);

    modifyHead_2(&head_2);
    Modify_value(&head3);
    printf("%p\n", head_2);
   // head_2->data = 10;
    printf("%d\n", head_2->data);
    printf("%d\n", head3.data);
    return 0;
}