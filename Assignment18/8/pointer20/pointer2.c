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
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to concatenate two linked lists
struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;

    return list1;
}

// Function to perform radix sort on an array of numbers
void radixSort(int arr[], int n) {
    // Find the maximum number to determine the number of digits
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Perform counting sort for every digit place value
    struct Node* buckets[10] = {NULL}; // Create 10 buckets for digits 0-9

    for (int exp = 1; max / exp > 0; exp *= 10) {
        // Place numbers into buckets based on the current digit
        for (int i = 0; i < n; i++) {
            int index = (arr[i] / exp) % 10;
            insert(&buckets[index], arr[i]);
        }

        // Concatenate all the buckets to form a new array
        int j = 0;
        for (int i = 0; i < 10; i++) {
            while (buckets[i] != NULL) {
                arr[j++] = buckets[i]->data;
                struct Node* temp = buckets[i];
                buckets[i] = buckets[i]->next;
                free(temp);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
