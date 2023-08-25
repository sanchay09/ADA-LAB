#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generate and fill array with random numbers
    srand(time(NULL)); // Seed the random number generator
    printf("\n\nRandomly generated elements:\n");
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999

    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    clock_t start_time = clock();  // Record the start time

    heapSort(arr, n);

    clock_t end_time = clock();    // Record the end time

    printf("\n\nSorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\n\nTime taken: %f seconds\n", time_taken);

    return 0;
}