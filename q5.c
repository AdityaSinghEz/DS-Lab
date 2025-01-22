// remove duplicate without sorting
// considering elements to be non zero
#include <stdio.h>
int main()
{
    printf("Enter the number of elements in array:\n");
    int n;
    scanf("%d", &n);
    printf("Enter the elements of array:\n");
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == a[i])
                    a[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            printf("%d ", a[i]);
    }
}