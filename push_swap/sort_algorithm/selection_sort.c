#include "sort_algorithm.h"

void selectionSort(int *arr, int n)
{
    int i, j;
    int max;

    printf("    초기 상태   \n");viewArr(arr, n);
    for (i = 0; i < n; i++)
    {
        max = 0;
        for (j = 1; j < n - i; j++)
            if (arr[max] < arr[j])
                max = j;
        swap(&arr[max], &arr[n - i - 1]);
        viewArr(arr, n);
    }
}