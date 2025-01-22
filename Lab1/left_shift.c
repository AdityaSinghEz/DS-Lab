#include <stdio.h>
int main()
{
    int n;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Enter elements:\n");
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int first = a[0];
    for (int i = 0; i < n - 1; i++)
        a[i] = a[i + 1];
    a[n - 1] = first;
    printf("Array after left shift:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}