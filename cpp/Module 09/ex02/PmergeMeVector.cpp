#include "PmergeMe.hpp"

void PmergeMe::vec_merge(std::vector<int> &posVec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = posVec[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = posVec[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            posVec[k] = L[i];
            ++i;
        }
        else
        {
            posVec[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1)
    {
        posVec[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        posVec[k] = R[j];
        ++j;
        ++k;
    }
}

void PmergeMe::vec_mergeSort(std::vector<int> &posVec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        vec_mergeSort(posVec, left, mid);
        vec_mergeSort(posVec, mid + 1, right);
        vec_merge(posVec, left, mid, right);
    }
}