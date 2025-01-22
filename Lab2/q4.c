// Find the kth largest no in an unsorted array
#include <stdio.h>
int main()
{
    printf("Enter the number of elements in array:\n");
    int n;
    scanf("%d", &n);
    printf("Enter the elements:\n");
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter k:\n");
    int k;
    scanf("%d", &k);
    int b[k];
    for (int j = 0; j < k; j++)
    {
        int flag = 0;
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
                flag = i;
            }
        }
        b[j] = max;
        a[flag] = 0;
    }
    printf("%d", b[k - 1]);
}