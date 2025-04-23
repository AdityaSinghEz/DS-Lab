#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} node;
node *create()
{
    node *nnode = (node *)malloc(sizeof(node));
    int x;
    printf("Enter data (-1 to exit):\n");
    scanf("%d", &x);
    if (x == -1)
        return 0;
    nnode->data = x;
    printf("Enter left child of %d\n", x);
    nnode->left = create();
    printf("Enter right child of %d\n", x);
    nnode->right = create();
    return nnode;
}
void main()
{
    node *root = 0;
    root = create();
    printf("Printing preorder:\n");
    preorder(root);
    printf("\nPrinting inorder:\n");
    inorder(root);
    printf("\nPrinting postorder:\n");
    postorder(root);
}
void preorder(node *root)
{
    if (root == 0)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if (root == 0)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == 0)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}