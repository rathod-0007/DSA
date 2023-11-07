#include <stdio.h>

int main() {
    int n; // Size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare an array of size n

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the elements of the array
    printf("Elements in the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
