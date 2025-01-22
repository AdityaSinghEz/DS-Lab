// bubble sort
#include <stdio.h>
#include <stdbool.h>
int main()
{
    printf("Enter the number of elements:\n");
    int n;
    scanf("%d", &n);
    printf("Enter the arrays to be sorted:\n");
    int a[n];
    for (int i = 0; i < n ; i++)
        scanf("%d", &a[i]);
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                cnt++;
                flag++;
            }
        }
        if (flag == 0)
            break;
    }
    printf("The number of swaps are= %d", cnt);
}