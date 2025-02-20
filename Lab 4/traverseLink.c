#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head, *temp, *nnode;
    head = 0;
    int choice = 1;
    while (choice)
    {
        nnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &nnode->data);
        nnode->next = 0;
        if (head == 0)
            head = temp = nnode;
        else
        {
            temp->next = nnode;
            temp = nnode;
        }
        printf("Press 1 to continue and 0 to exit:\n");
        scanf("%d", &choice);
    }
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}