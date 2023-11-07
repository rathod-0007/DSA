#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

// Structure to represent a queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to create an empty queue
void createQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    if (q->rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    if (q->front == -1)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue element.\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }
        return item;
    }
}

// Function to count duplicates in the queue
int countDuplicates(struct Queue *q) {
    int count = 0;
    int visited[MAX_SIZE] = {0}; // Array to keep track of visited elements

    // Iterate through the queue
    for (int i = q->front; i <= q->rear; i++) {
        visited[q->items[i]]++;
        if (visited[q->items[i]] > 1) {
            count++;
        }
    }
    return count;
}

// Function to find the maximum element in the queue
int findMax(struct Queue *q) {
    int max = q->items[q->front];
    for (int i = q->front + 1; i <= q->rear; i++) {
        if (q->items[i] > max) {
            max = q->items[i];
        }
    }
    return max;
}

// Function to count the occurrences of the maximum element in the queue
int countMaxOccurrences(struct Queue *q) {
    int max = findMax(q);
    int count = 0;
    for (int i = q->front; i <= q->rear; i++) {
        if (q->items[i] == max) {
            count++;
        }
    }
    return count;
}

int main() {
    struct Queue q;
    createQueue(&q);

    int size, element;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &element);
        enqueue(&q, element);
    }

    int duplicates = countDuplicates(&q);
    int maxOccurrences = countMaxOccurrences(&q);

    printf("Number of duplicates in the queueis: %d\n", duplicates);
printf("Number of occurrences of the maximum element: %d\n", maxOccurrences);}
