#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *newNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert(node *root, int data)
{
    if (root == NULL)
        root = newNode(data);
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int count = 0;
int result;
int found = 0;

void kthSmallest(node *root, int k)
{
    if (root == NULL || found == 1)
        return;
    kthSmallest(root->left, k);
    count++;
    if (count == k)
    {
        result = root->data;
        found = 1;
        return;
    }
    kthSmallest(root->right, k);
}

int main()
{
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 420);
    root = insert(root, 69);

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    count = 0;
    found = 0;
    kthSmallest(root, k);
    if (found == 1)
        printf("%dth min element is %d\n", k, result);
    else
        printf("k is larger than the number of nodes\n");
}
