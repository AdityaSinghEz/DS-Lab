// insertion sort
#include <stdio.h>
int main()
{
    printf("Enter the number of elements in the array:\n");
    int n;
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
            cnt++;
        }
        a[j + 1] = temp;
    }
    printf("%d", cnt);
}