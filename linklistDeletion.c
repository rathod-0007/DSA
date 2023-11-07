#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

struct node *delete_first(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

int main()
{
    // allocate memory to the nodes
    // first allocate memory and then traverse
    struct node *head, *head2, *head3;
    head = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head3 = (struct node *)malloc(sizeof(struct node));
    head->data = 8;
    head->next = head2;

    head2->data = 6;
    head2->next = head3;

    head3->data = 9;
    head3->next = NULL;

    printf("linked list:  ");
    traverse(head);

    printf("\nlist at first deletion:  ");
    head = delete_first(head);
    traverse(head);
}