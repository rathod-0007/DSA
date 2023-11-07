#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;               // Info part storing 4 digits
    struct Node* prev;      // Pointer to the previous node
    struct Node* next;      // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%04d -> ", head->data); // Print 4-digit groups with leading zeros
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}
  // Function to add two numbers represented by doubly linked lists
struct Node* addNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int digit1 = (num1 != NULL) ? num1->data : 0;
        int digit2 = (num2 != NULL) ? num2->data : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10000; // Calculate carry for the next iteration

        insertEnd(&result, sum % 10000);

        if (num1 != NULL) num1 = num1->prev;
        if (num2 != NULL) num2 = num2->prev;
    }

    return result;
}


int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    char input1[100]; // Assuming a maximum input length of 100 characters
    char input2[100]; // Assuming a maximum input length of 100 characters

    printf("Enter the first number: ");
    scanf("%s", input1);

    printf("Enter the second number: ");
    scanf("%s", input2);
    
    // Parse the first input number and create the first doubly linked list
    int num = 0;
    int digitsProcessed = 0;

    for (int i = strlen(input1) - 1; i >= 0; i--) {
        int digit = input1[i] - '0';
        num = num * 10 + digit;
        digitsProcessed++;

        if (digitsProcessed == 4) {
            insertEnd(&head1, num);
            num = 0;
            digitsProcessed = 0;
        }
    }

    if (digitsProcessed > 0) {
        insertEnd(&head1, num);
    }

    // Parse the second input number and create the second doubly linked list
    num = 0;
    digitsProcessed = 0;

    for (int i = strlen(input2) - 1; i >= 0; i--) {
        int digit = input2[i] - '0';
        num = num * 10 + digit;
        digitsProcessed++;

        if (digitsProcessed == 4) {
            insertEnd(&head2, num);
            num = 0;
            digitsProcessed = 0;
        }
    }

    if (digitsProcessed > 0) {
        insertEnd(&head2, num);
    }

    // Print the input numbers
    printf("First number: ");
    printList(head1);
    printf("Second number: ");
    printList(head2);

    // Perform addition and print the result
    struct Node* result = addNumbers(head1, head2);
    printList(result);

    // Free allocated memory for all lists
    freeList(head1);
    freeList(head2);
    freeList(result);

    return 0;
}
