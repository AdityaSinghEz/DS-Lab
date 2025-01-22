#include <stdio.h>
int main()
{
    printf("Enter n:\n");
    int n;
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);
}