#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(char data)
{
    Node *nnode = (Node *)malloc(sizeof(Node));
    nnode->data = data;
    nnode->prev = 0;
    nnode->next = 0;
    return nnode;
}

Node *insertNode(Node *head, char data)
{
    Node *nnode = createNode(data);
    if (head == 0)
        head = nnode;
    else
    {
        Node *temp = head;
        while (temp->next != 0)
            temp = temp->next;
        temp->next = nnode;
        nnode->prev = temp;
    }
    return head;
}

int isPalindrome(Node *head)
{
    Node *start = head;
    Node *end = head;
    while (end->next != 0)
        end = end->next;
    while (start != end && start->prev != end)
    {
        if (start->data != end->data)
            return 0;
        start = start->next;
        end = end->prev;
    }
    return 1;
}

int main()
{
    char str[100];
    Node *head = 0;
    printf("Enter a string of digits: ");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
        head = insertNode(head, str[i]);
    if (isPalindrome(head))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
}
