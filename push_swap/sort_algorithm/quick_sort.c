#include "sort_algorithm.h"

void PrintSpace(int n)
{
    int i = 0;
    for (i = 0; i<n; i++)
    {
        printf("   ");
    }
}

void quickSort_s(int *arr, int n)
{
    int left, right;

    if (n <= 1)
        return ;
    
    while (1)
    {
        for (left = 1; (left < n) && (arr[0] >= arr[left]); left++);
        for (right = n - 1; (right > 0) && (arr[0] < arr[right]); right--);
        if (left < right)
        {
            swap(&arr[left], &arr[right]);
            PrintSpace(arr - origin);
            viewArr(arr, n);
        }
        else
            break;
    }
    swap(&arr[0], &arr[right]);
    PrintSpace(arr - origin);
    viewArr(arr, n);
    quickSort_s(arr, right);
    quickSort_s(arr + left, n - left);
}

void quickSort(int *arr, int n)
{
    printf("비어 있는 수는 pivot(기준 수)\n");
    printf("    초기 상태   \n");viewArr(arr, n);
    quickSort_s(arr, n);
    viewArr(arr, n);
}