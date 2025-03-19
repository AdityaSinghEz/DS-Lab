
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *first = NULL;

node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode)
    {
        printf("Memory error\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertnode(int data)
{
    node *newnode = createnode(data);
    if (first == NULL)
    {
        first = newnode;
        return;
    }

    node *temp = first;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void deletenode(int index, int n)
{
    node *p, *q = NULL;
    if (first == NULL || index < 1 || index > n)
        return;
    if (index == 1)
    {
        p = first;
        first = p->next;
        free(p);
        return;
    }
    p = first;
    for (int i = 1; i < index && p != NULL; i++)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        return;
    q->next = p->next;
    free(p);
}

void printList()
{
    node *temp = first;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertnode(data);
    }

    printf("Linked List: ");
    printList();

    int index;
    printf("Enter the index of the node to delete (1-%d): ", n);
    scanf("%d", &index);

    deletenode(index, n);

    printf("Linked List after deletion: ");
    printList();
}
