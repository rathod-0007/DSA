#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    struct Node* f;//f is front element 
    struct Node* r;//r is rear element 
};
struct Node {
    int data;
    struct Node* next;
};
void startQueue(struct Queue* q) {
    q->f = NULL;
    q->r = NULL;
}

int isEmpty(struct Queue* q) {
    return (q->f == NULL);
}
//adding element in queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->f = newNode;
        q->r = newNode;
    }
    else {
        q->r->next = newNode;
        q->r = newNode;
    }
}
//removing element in queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct Node* temp = q->f;
    int data = temp->data;

    q->f = q->f->next;

    if (q->f == NULL)
        q->r = NULL;

    free(temp);//freeing the memeory after removing elements
    return data;
}

int countDuplicates(struct Queue* q) {//function to count the duplicates in queue
    int count = 0;

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return count;
    }

    struct Node* current = q->f;

    while (current != NULL) {
        int data = current->data;
        int duplicateCount = 0;
        struct Node* temp = current->next;

        while (temp != NULL) {
            if (temp->data == data)
                duplicateCount++;

            temp = temp->next;
        }

        if (duplicateCount > 0)
            count += duplicateCount;

        current = current->next;
    }

    return count;
}

int repeatedFrequency(struct Queue* q) {//function to find the maximum frequency
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int maxCount = 0;
    int maxFreq = q->f->data;

    struct Node* current = q->f;

    while (current != NULL) {
        int data = current->data;
        int count = 0;
        struct Node* temp = current->next;

        while (temp != NULL) {
            if (temp->data == data)
                count++;

            temp = temp->next;
        }

        if (count > maxCount) {
            maxCount = count;
            maxFreq = data;
        }

        current = current->next;
    }

    return maxFreq;
}

int main() {//main function call
    struct Queue q;
    startQueue(&q);

    int n, element;
    printf("Enter no:of elements you require in the Queue: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        enqueue(&q, element);//took &q bcz we gave q as a pointer 
    }

    int duplicateCount = countDuplicates(&q);
    printf("Number of duplicates are: %d\n", duplicateCount);

    int max_freq = repeatedFrequency(&q);
    printf("Element with maximum frequency: %d\n", max_freq);

    return 0;
}
