#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of a linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to find the maximum value in the linked list
int findMax(struct Node* head) {
    int max = head->data;
    while (head != NULL) {
        if (head->data > max) {
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

// Function to perform counting sort on the linked list based on a digit's place
void countSort(struct Node** head, int exp) {
    if (*head == NULL) {
        return;
    }

    int count[10] = {0};
    struct Node* output = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        count[(current->data / exp) % 10]++;
        current = current->next;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    current = *head;
    while (current != NULL) {
        insert(&output, current->data);
        current = current->next;
    }

    current = *head;
    while (current != NULL) {
        int index = (current->data / exp) % 10;
        current->data = output->data;
        output = output->next;
        count[index]--;
        current = current->next;
    }
}

// Radix Sort function for linked list
void radixSort(struct Node** head) {
    int max = findMax(*head);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(head, exp);
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert(&head, 170);
    insert(&head, 45);
    insert(&head, 75);
    insert(&head, 90);
    insert(&head, 802);
    insert(&head, 24);
    insert(&head, 2);
    insert(&head, 66);

    printf("Original Linked List: ");
    printList(head);

    radixSort(&head);

    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}
