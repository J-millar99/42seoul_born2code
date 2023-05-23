#include "sort_algorithm.h"

void bubbleSort(int *arr, int n)
{
    int i, j;

    printf("    초기 상태   \n");viewArr(arr, n);
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                viewArr(arr, n);
            }
        }
    }
}