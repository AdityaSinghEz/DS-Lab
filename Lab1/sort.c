#include <stdio.h>
int main()
{
    printf("Enter n:\n");
    int n;
    scanf("%d", &n);
    printf("Enter elements:\n");
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int swap = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                swap++;
            }
        }
        if (swap == 0)
            break;
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}