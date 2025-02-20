#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter integers %d:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i += 2)
    {
        int pivot = i;
        for (int j = i + 2; j < n; j += 2)
        {
            if (arr[j] < arr[pivot])
                pivot = j;
        }
        int temp = arr[i];
        arr[i] = arr[pivot];
        arr[pivot] = temp;
    }
    for (int i = 3; i < n; i += 2)
    {
        int key = arr[i];
        int j = i - 2;
        while (j >= 1 && arr[j] > key)
        {
            arr[j + 2] = arr[j];
            j -= 2;
        }
        arr[j + 2] = key;
    }
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}