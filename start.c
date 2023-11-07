#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversing_list(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{ // allocating the memory to 3 nodes i.e., head with the pointer
    struct node *head, *head2, *head3;
    head = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head3 = (struct node *)malloc(sizeof(struct node));

    head->data = 5;     // -->LINKING head to head1
    head->next = head2; // pointing the next space in the head to head1

    head2->data = 8; // LINKING head1 to head2
    head2->next = head3;

    head3->data = 15;   // LINKING head2 to head3
    head3->next = NULL; // head3 stops pointing to next element when it reaches to NULL

    traversing_list(head); // calling traversing_list function by kepping "head" as first node element to "ptr"
}