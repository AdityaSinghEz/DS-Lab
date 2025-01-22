#include <stdio.h>
int main()
{
    int n, posi, value;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Enter elements:\n", n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the position:\n");
    scanf("%d", &posi);
    posi++;
    if (posi > n + 1 || posi <= 0)
        printf("Invalid posi\n");
    else
    {
        printf("Enter the value to insert:\n");
        scanf("%d", &value);
        for (int i = n - 1; i >= posi - 1; i--)
            a[i + 1] = a[i];
        a[posi - 1] = value;
        printf("Final array is:\n");
        for (int i = 0; i <= n; i++)
            printf("%d ", a[i]);
    }
}