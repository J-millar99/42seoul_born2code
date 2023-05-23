#include "sort_algorithm.h"

void swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

void viewArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}