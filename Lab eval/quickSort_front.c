#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (arr[i] <= pivot && i < end)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[start], &arr[j]);
    return j;
}
void QuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = partition(arr, start, end);
        QuickSort(arr, start, mid - 1);
        QuickSort(arr, mid + 1, end);
    }
}
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    QuickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}