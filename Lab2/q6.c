// check freq
#include <stdio.h>
int main()
{
    printf("Enter number of elements in array:\n");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            int freq = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                {
                    freq++;
                    a[j] = 0;
                }
            }
            printf("freq of %d is %d\n", a[i], freq);
        }
    }
}