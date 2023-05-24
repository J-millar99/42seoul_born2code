#include "sort_algorithm.h"

void mergeSort_s(int *arr, int n)
{
    int ahalf = n / 2;
    int bhalf = n - ahalf;
    int ai = 0, bi = ahalf;
    int i = 0;
    int* tarr = 0;//static int tarr[100000];

    if (n <= 1)
        return;

    mergeSort_s(arr, ahalf);
    mergeSort_s(arr+ahalf, bhalf);
    tarr = (int*)malloc(sizeof(int) * n);
    memcpy(tarr, arr, sizeof(int) * n);
    
    while ((ai < ahalf) && (bi < n))
    {
        if (tarr[ai] <= tarr[bi])
        {
            arr[i] = tarr[ai];
            ai ++;
        }
        else
        {
            arr[i] = tarr[bi];
            bi++;
        }
        i++;
    }
    while (ai < ahalf)
    {
        arr[i] = tarr[ai];
        i++;
        ai++;
    }
    while (bi < n)
    {
        arr[i] = tarr[bi];
        i++;
        bi++;
    }
    free(tarr);
}

void mergeSort(int *arr, int n)
{
    printf("    초기 상태   \n");viewArr(arr, n);
    mergeSort_s(arr, n);
    viewArr(arr, n);
}
