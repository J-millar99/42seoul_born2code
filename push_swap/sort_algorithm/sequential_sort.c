#include "sort_algorithm.h"

void sequenceSort(int *arr, int n)
{
    int i, j;

    printf("    초기 상태   \n");viewArr(arr, n);
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
                viewArr(arr, n);
            }
        }
    }
}