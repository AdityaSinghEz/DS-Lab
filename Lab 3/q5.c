#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the matrix:\n");
    scanf("%d", &n);
    if (n < 3)
    {
        printf("Matrix size should be at least 3x3\n");
        return 0;
    }
    float m[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &m[i][j]);
        }
    }
    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%0.2f ", m[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            float sum = 0;
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    sum += m[k][l];
                }
            }
            float avg = sum / 9.0;
            m[i + 1][j + 1] = avg;
        }
    }
    printf("Modified Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f ", m[i][j]);
        }
        printf("\n");
    }
}