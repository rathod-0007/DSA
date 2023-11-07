#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int evaluatePostfix(char *expression)
{
    Stack stack;
    initialize(&stack);
    int i = 0;
    while (expression[i] != '\0')
    {
        if (isdigit(expression[i]))
        {
            push(&stack, expression[i] - '0'); // Convert character to integer value and push to stack
        }
        else
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i])
            {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                push(&stack, operand1 / operand2);
                break;
            }
        }
        i++;
    }
    return pop(&stack);
}

int main()
{
    char expression[MAX_SIZE];

    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluatePostfix(expression);

    printf("Result: %d\n", result);

    return 0;
}
