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
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j] && a[j] % 2 != 0)
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    printf("The odd number sorted array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}