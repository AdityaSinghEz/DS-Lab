#include <stdio.h>
int main()
{
    printf("Enter number of elements:\n");
    int n;
    scanf("%d", &n);
    printf("Enter array elements:\n");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element:\n");
        scanf("%d", &a[i]);
    }
    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}