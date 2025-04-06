#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = 0;
    return new_node;
}

void insertNode(Node **head, int data)
{
    Node *new_node = createNode(data);
    if (*head == 0)
        *head = new_node;
    else
    {
        Node *temp = *head;
        while (temp->next != 0)
            temp = temp->next;
        temp->next = new_node;
    }
}

int detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != 0 && fast->next != 0)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

void removeLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != 0 && fast->next != 0)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = 0;
    }
}

int main()
{
    Node *head = 0;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    head->next->next->next->next = head->next;
    if (detectLoop(head))
    {
        removeLoop(head);
        printf("Loop removed\n");
    }
    else
        printf("No loop detected\n");
}
