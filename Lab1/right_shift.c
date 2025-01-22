#include <stdio.h>
int main()
{
    printf("Enter n:\n");
    int n;
    scanf("%d", &n);
    int a[n + 1];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int last = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
        a[i + 1] = a[i];
    a[0] = last;
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}