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
void merge(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        print(head2);
        return;
    }
    if (head2 == NULL)
    {
        print(head1);
        return;
    }
    node *temp = head1;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = head2;
    temp = head1;
    int a[1000], n = 0;
    while (temp)
    {
        a[n++] = temp->data;
        temp = temp->next;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    temp = head1;
    for (int i = 0; i < n; i++)
    {
        temp->data = a[i];
        temp = temp->next;
    }
    print(head1);
}
int main()
{
    int arr1[] = {4, 2, 0, 6, 9};
    int arr2[] = {1, 3, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    node *head1 = arr_to_link(arr1, size1);
    node *head2 = arr_to_link(arr2, size2);
    merge(head1, head2);
}