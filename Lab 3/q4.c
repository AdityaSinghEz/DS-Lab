#include <stdio.h>
int count = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (1)
    {
        while (i <= j && a[i] <= pivot)
            i++;
        while (i <= j && a[j] >= pivot)
            j--;
        if (i >= j)
            break;
        swap(&a[i], &a[j]);
    }
    swap(&a[low], &a[j]);
    return j;
}
void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        count++;
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}
int main()
{
    int n;
    printf("Enter the size:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter integers:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    count = 0;
    quicksort(a, 0, n - 1);
    printf("Number of pivot operations:%d\n", count);
}