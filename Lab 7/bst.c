#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} node;
node *FindMin(node *root)
{
    while (root->left != 0)
        root = root->left;
    return root;
}
node *insert(node *root, int data)
{
    if (root == 0)
    {
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = 0;
        root->right = 0;
    }
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
}
node *delete(node *root, int data)
{
    if (root == 0)
        return root;
    else if (data < root->data)
        root->left = delete (root->left, data);
    else if (data > root->data)
        root->right = delete (root->right, data);
    else
    {
        if (root->left == 0 && root->right == 0)
            free(root);
        else if (root->left == 0)
        {
            node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == 0)
        {
            node *temp = root;
            root = root->left;
            free(root);
        }
        else
        {
            node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
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
int main()
{
    node *root = 0;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 100);
    printf("Printing preorder:\n");
    preorder(root);
    printf("\nPrinting inorder:\n");
    inorder(root);
    printf("\nPrinting postorder:\n");
    postorder(root);
    delete (root, 30);
    printf("\nPrinting preorder:\n");
    preorder(root);
}