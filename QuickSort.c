
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Partition function
int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (1) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

// Quick Sort
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

int main() {
    int sizes[] = {10, 50, 100, 500, 1000, 5000};
    int numSizes = 6;

    printf("InputSize\tTime(seconds)\n");

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));

        // Generate random numbers
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }

        clock_t start = clock();
        for(int i=0;i<1000;i++){

        quickSort(arr, 0, n - 1);
        }
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%f\n", n, time_taken);

        free(arr);
    }

    return 0;
}
