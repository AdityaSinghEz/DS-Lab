#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
node *arr_to_link(int arr[], int size)
{
    if (size == 0)
        return NULL;
    node *head = (node *)malloc(sizeof(node));
    head->data = arr[0];
    head->next = NULL;
    node *mover = head;
    for (int i = 1; i < size; i++)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = arr[i];
        temp->next = NULL;
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void even_odd(node *head)
{
    if (head == NULL || head->next == NULL)
        return;
    node *odd = head;
    node *even = head->next;
    node *oddx = odd;
    node *evenx = even;
    while (odd && even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        if (odd)
        {
            even->next = odd->next;
            even = even->next;
        }
    }
    printf("Odd indexed nodes:\n");
    print(oddx);
    printf("Even indexed nodes:\n");
    print(evenx);
}
int main()
{
    int arr[] = {4, 2, 0, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = arr_to_link(arr, size);
    printf("Original List:\n");
    print(head);
    even_odd(head);
}