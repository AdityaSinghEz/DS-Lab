#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter integers: %d\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[pivot])
                pivot = j;
        int temp = a[i];
        a[i] = a[pivot];
        a[pivot] = temp;
    }
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}