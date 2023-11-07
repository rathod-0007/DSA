#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr)
{
    while (ptr != NULL) // here ptr is nothing but head itself
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertbegin(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct node *insertLast(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p->next = ptr;
        ptr->next = NULL;
        return head;
    }
}
int main()
{

    // allocating the memory to the nodes
    struct node *head, *head1, *head2, *head3, *head4, *head5, *head6, *head7;

    head = (struct node *)malloc(sizeof(struct node));
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head3 = (struct node *)malloc(sizeof(struct node));
    head4 = (struct node *)malloc(sizeof(struct node));
    head5 = (struct node *)malloc(sizeof(struct node));
    head6 = (struct node *)malloc(sizeof(struct node));
    head7 = (struct node *)malloc(sizeof(struct node));

    // linking first head to next node
    head->data = 8;
    head->next = head1;

    head1->data = 14;
    head1->next = head2;

    head2->data = 3;
    head2->next = head3;

    head3->data = 10;
    head3->next = head4;

    head4->data = 9;
    head4->next = head5;

    head5->data = 28;
    head5->next = head6;

    head6->data = 2;
    head6->next = head7;

    head7->data = 4;
    head7->next = NULL;

    // traverse(head); // this head is nothing but ptr itself we are ptr so that there would be no confusion

    // head = insertbegin(head, 15);

    head = insertLast(head, 21);
    traverse(head);
}