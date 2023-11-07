#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100//maximum size is 100

struct Stack {
    char items[MAX_SIZE];//took char bcz input for palindrome is string
    int top;
};

// Function to create an empty stack
struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack)
{
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item)
{
    if (stack->top == MAX_SIZE - 1) {
        printf("\nStack Overflow");
    }
    else {
        stack->top++;
        stack->items[stack->top] = item;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("\nStack Underflow");
        return '\0';
    }
    else {
        char item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str)
{
    int len = strlen(str);
    struct Stack* stack = createStack();

    // Push each character onto the stack
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }

    // Pop each character and build the reversed string
    char reversed[MAX_SIZE];
    int index = 0;
    while (!isEmpty(stack)) {
        reversed[index++] = pop(stack);
    }
    reversed[index] = '\0';

    // Compare the original string with the reversed string
    if (strcmp(str, reversed) == 0) {
        return 1; // Palindrome
    }
    else {
        return 0; // Not a palindrome
    }
}

int main()
{
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    }
    else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
