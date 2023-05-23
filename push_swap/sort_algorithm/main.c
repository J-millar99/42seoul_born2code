#include "sort_algorithm.h"

int main(int ac, char *av[])
{
    int *arr;

    if (ac < 2)
        return (1);
    arr = (int *)malloc(sizeof(int) * ac - 1);
    for (int i = 0; i < ac - 1; i++)
        arr[i] = atoi(av[i + 1]);
    origin = arr;
    on = ac - 1;
    //printf("====순차 정렬====\n");sequenceSort(arr, ac - 1);
    //printf("====버블 정렬====\n");bubbleSort(arr, ac - 1);
    //printf("====선택 정렬====\n");selectionSort(arr, ac - 1);
    //printf("====삽입 정렬====\n");insertionSort(arr, ac - 1);
    //printf("==== 쉘 정렬====\n");shellSort(arr, ac - 1);
    //printf("==== 퀵 정렬====\n");quickSort(arr, ac - 1);
    printf("====병합 정렬====\n");mergeSort(arr, ac - 1);
    //printf("==== 힙 정렬====\n");heapSort(arr, ac - 1);
    return (0);
}