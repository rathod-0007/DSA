#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void addAtBeginning(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void addAtMiddle(int data, int position)
{
    int i;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    struct node *current = head;
    for (i = 1; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void addAtEnd(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void deleteFromMiddle(int position)
{
    int i;
    struct node *current = head;
    struct node *previous = NULL;
    for (i = 1; i < position && current != NULL; i++)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    previous->next = current->next;
    free(current);
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *current = head;
    struct node *previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    if (previous == NULL)
    {
        head = NULL;
    }
    else
    {
        previous->next = NULL;
    }
    free(current);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayReverse(struct node *current)
{
    if (current == NULL)
    {
        return;
    }
    displayReverse(current->next);
    printf("%d ", current->data);
}

struct node *search(int data)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }
    return 0;
}
