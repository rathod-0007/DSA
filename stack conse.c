#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int data)
{
    if (top >= STACK_SIZE - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = data;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

bool check_consecutive_pairs()
{
    int num_pairs = (top + 1) / 2; // Number of pairs in the stack
    int i;
    for (i = 0; i < num_pairs; i++)
    {
        int num1 = pop();
        int num2 = pop();
        if (abs(num1 - num2) != 1)
        { // Check if the absolute difference between the two numbers is 1
            return false;
        }
    }
    // If the stack has an odd number of elements, the top element is left out of a pair
    if (top >= 0)
    {
        pop();
    }
    return true;
}

int main()
{
    int arr[] = {4, 5, -2, -3, 11, 10, 5, 6, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    for (i = 0; i < n; i++)
    {
        push(arr[i]);
    }
    if (check_consecutive_pairs())
    {
        printf("All successive pairs are consecutive\n");
    }
    else
    {
        printf("Not all successive pairs are consecutive\n");
    }
    return 0;
}
