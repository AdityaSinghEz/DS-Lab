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
    node *tempest = head;
    for (int i = 1; i < size; i++)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = arr[i];
        temp->next = NULL;
        tempest->next = temp;
        tempest = temp;
    }
    return head;
}
void freq(node *head)
{
    if (head == NULL)
        return;
    node *temp = head;
    int a[1000] = {0};
    while (temp != NULL)
    {
        a[temp->data]++;
        temp = temp->next;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (a[i] > 0)
        {
            printf("%d  %d\n", i, a[i]);
        }
    }
}
int main()
{
    int arr[] = {4,2,0,6,9,4,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = arr_to_link(arr, size);
    freq(head);
}