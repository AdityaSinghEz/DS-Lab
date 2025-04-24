#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *reverse(node *head, node *tail)
{
}
node *delete(node *head, node *tail, int count)
{
    int ind;
    printf("Enter the index:\n");
    scanf("%d", &ind);
    node *temp = head;
    if (ind < 1 || ind > count)
        printf("INVALID INPUT");
    else
    {
        if (ind == 1)
        {
            head = head->next;
            tail = head;
            free(temp);
        }
        else if(ind==count){
            
        }
    }
    return head;
}
node *insert(node *head, node *tail, int count)
{
    int ind;
    printf("Enter the index:\n");
    scanf("%d", &ind);
    node *nnode = (node *)malloc(sizeof(node));
    printf("Enter data:\n");
    scanf("%d", &nnode->data);
    node *temp = head;
    if (ind < 1 || ind > count + 1)
        printf("INVALID INPUT");
    else
    {
        if (ind == 1)
        {
            head = nnode;
            nnode->next = temp;
            tail->next = head;
        }
        else if (ind == count + 1)
        {
            tail->next = nnode;
            tail = nnode;
            tail->next = head;
        }
        else
        {
            int i = 1;
            while (i < ind - 1)
            {
                i++;
                temp = temp->next;
            }
            nnode->next = temp->next;
            temp->next = nnode;
        }
    }
    return head;
}
void display(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
int main()
{
    node *head = 0, *tail;
    int choice = 1;
    int count = 0;
    while (choice)
    {
        count++;
        node *nnode = (node *)malloc(sizeof(node));
        printf("Enter data:\n");
        scanf("%d", &nnode->data);
        nnode->next = 0;
        if (head == 0)
            head = tail = nnode;
        else
        {
            tail->next = nnode;
            tail = nnode;
        }
        tail->next = head;
        printf("Press 0 to exit or any other number to continue inputing values:\n");
        scanf("%d", &choice);
    }
    display(head);
    head=insert(head,tail,count);
    display(head);
}