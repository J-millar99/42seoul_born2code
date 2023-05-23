#include "sort_algorithm.h"

void shellSort(int *arr, int n)
{
    int i, step;

    printf("    초기 상태   \n");viewArr(arr, n);
    for (step = n / 2; step > 0; step /= 2)//step의 폭을 1/2로 줄여간다.
        for (i = 0; i < step; i++) //step 간격에 있는 요소들을 삽입정렬
            shellInsertionSort(arr + i, n - i, step);
}

void shellInsertionSort(int *arr, int n, int step)
{
    int i, j;

    for (i = step; i < n; i += step)//정렬 대상 원소는 step 간격으로 이동
    {
        for (j = i; j > 0; j -= step)//step 간격으로 앞으로 이동
        {
            if (arr[j - step] > arr[j])//앞쪽이 더 클 때
            {
                swap(&arr[j - step], &arr[j]);//교환
                viewArr(origin, on);
            }
            else
                break;
        }
    }
}