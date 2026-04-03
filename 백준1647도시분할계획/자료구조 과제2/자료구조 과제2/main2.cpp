#include <stdio.h>
#include <stdlib.h>

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

// Complete the following function to insert a new Node at a given position
void insertAtPosition(Node** head, int position, int data) {
   Node* newNode = (Node*)malloc(sizeof(Node)); 
   if (newNode == NULL) { return; }
   Node* temp = *head;
   newNode->data = data;
   
	// Incase for the desired position is the head
   if ( temp != NULL && position == 1) {
       newNode->next = temp;
       *head = newNode;
       return;
    }

    // Otherwise, find the desired position
   while (temp != NULL && position - 2 > 0) {
       position--;
       temp = temp->next;
   }

	// If the position is out of range
   if (temp == NULL || position <= 0) {
       printf("you cant insert this %d because its position is out of range\n", newNode->data);
       return;
   }
	// Insert the new Node
   newNode->next = temp->next;
   temp->next = newNode;
   return;
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

int main() {
    Node* head = NULL;

    // Data insertion
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    printList(head);

    // Additional data insertion at the front
    insertAtHead(&head, 5);
    printList(head);

    // Search operation
    int tar_val = 20;
    bool isFound = searchNode(head, tar_val);
    if (isFound) {
        printf("Found Node: %d\n", tar_val);
    }
    else {
        printf("Node not found.\n");
    }

    // Delete operation
    deleteNode(&head, 20);
    printList(head);

    //insertAtPosition opoeration 과제 부분
    printf("node 40 added to second position\n");
    insertAtPosition(&head, 2, 40);
    printf("node 80 added to third position\n");
    insertAtPosition(&head, 3, 80);
    printf("node 100 added to 100 position\n");
    insertAtPosition(&head, 100, 100);
    printf("node 100 added to 1 position\n");
    insertAtPosition(&head, 1, 100);
    printf("node 100 added to -1 position\n");
    insertAtPosition(&head, -1, 100);
    printf("after change\n");
    printList(head);

    // Free the linked list
    freeList(&head);

    return 0;
}
