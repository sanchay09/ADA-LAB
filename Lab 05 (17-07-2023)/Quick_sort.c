#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap (int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort (int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition (arr, low, high);
        quickSort (arr, low, pi - 1);
        quickSort (arr, pi + 1, high);
    }
}

int main ()
{
    int n;
    clock_t start_t, end_t;
    double total_t;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the maximum value of the elements: ");
    int max;

    scanf("%d", &max);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % max;
    }

    printf("\nUnsorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    start_t = clock();
        printf("\n\nStarting of the program: %ld\n", start_t);

    quickSort (arr, 0, n - 1);

    printf("\n\n\nSorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    end_t = clock();
        printf("\n\nEnd of the program: %ld\n", end_t);

    total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
        printf("\n\nTotal time taken by CPU: %f\n", total_t);

    return 0;
}
