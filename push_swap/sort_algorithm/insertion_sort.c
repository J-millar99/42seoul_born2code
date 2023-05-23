#include "sort_algorithm.h"

void insertionSort(int *arr, int n)
{
    int i, j;

    printf("    초기 상태   \n");viewArr(arr, n);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j > -1; j--)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                viewArr(arr, n);
            }
            else
                break;
        }
    }
}