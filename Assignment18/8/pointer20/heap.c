#include<stdio.h>

int n;
int arr[100];

void insert() {
    n = n + 1;
    printf("Enter the value for insertion: ");
    scanf("%d", &arr[n - 1]);
}

void heapify(int i) {
    int  smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < n && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
    }

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(smallest);
    }
}

void buildHeap() {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

void display() {
    printf("Heap elements after operations:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int ch;

    printf("Enter the number of elements in the heap: ");
    scanf("%d", &n);

    printf("Enter the elements of the heap:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("Enter a choice\n");
        printf("1: Insertion\n");
        printf("2: Heapify\n");
        printf("3: Display\n");
        printf("4: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                buildHeap();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}