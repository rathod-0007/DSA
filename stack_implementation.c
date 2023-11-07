#include <stdio.h>
#include <stdlib.h> //for make use of malloc

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{ // in palce of s we are taking ptr
    if (ptr->top == -1)
    {
        return 1; // true
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{ // in palce of s we are taking ptr
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// push function i.e., inserting elements in stack
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    { //-->using isFull function to check
        printf("Stack Overflow\n");
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    { //---.>using isEmpty to check
        printf("Stack Underflow cannot pop\n");
        return -1; // since underflow
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top]; // returns top element
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0]; // index 0 gives bottom element
}

int main() /////// we are using --->"s"<--- as the input variable
{
    struct stack *s; // pointer is accesed by ->
    s->size = 7;
    s->top = -1; // index of arr is -1 mean stack is empty
    s->arr = (int *)malloc(s->size * sizeof(int));

    // pushing an element
    s->arr[0] = 4;
    s->top++; // oushing valus one by one

    // checking if stack is empty
    if (isEmpty(s))
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack is not empty\n");
    }
    push(s, 5);
    push(s, 5);
    push(s, 5);
    push(s, 5);
    push(s, 6);
    push(s, 5); // ipushed 7 elements as size was taken as=7
    printf("after pushing full:%d\n", isFull(s));

    pop(s);
    printf("after pop : %d\n", pop(s)); // LIFO(last in first out)
}
