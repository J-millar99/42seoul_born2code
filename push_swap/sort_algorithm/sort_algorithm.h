#ifndef SORT_ALGORITHM_H
# define SORT_ALGORITHM_H
# include <stdlib.h>
# include <stdio.h>

int *origin;
int on;

void swap(int *a, int *b);
void viewArr(int *arr, int n);
void sequenceSort(int *arr, int n);
void bubbleSort(int *arr, int n);
void selectionSort(int *arr, int n);
void insertionSort(int *arr, int n);
void shellSort(int *arr, int n);
void shellInsertionSort(int *arr, int n, int step);
void quickSort(int *arr, int n);
void mergeSort(int *arr, int n);
// void heapSort(int *arr, int n);

#endif