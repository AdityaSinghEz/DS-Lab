//floating avg
#include <stdio.h>
int main()
{
    printf("Enter the size of range:\n");
    int n;
    scanf("%d", &n);
    printf("Enter the size of the array:\n");
    int size;
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    int a[size];
    for (int i = 0; i < size; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < size; i++)
    {
        float avg = 0;
        int cnt = 0;
        if (i < n - 1)
        {
            for (int j = 0; j <= i; j++)
            {
                avg += a[j];
                cnt++;
            }
        }
        else
        {
            for (int j = i - n + 1; j <= i; j++)
            {
                avg += a[j];
                cnt++;
            }
        }
        avg = avg / cnt;
        printf("%0.2f\n", avg);
    }
}