#include "PmergeMe.hpp"
PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &ref){ (void)ref; }
PmergeMe &PmergeMe::operator=(const PmergeMe &ref){ (void)ref; return *this; }

PmergeMe::PmergeMe(char *argv[])
{
    int num;
    size_t idx = 1;
    while (argv[idx])
    {
        num = ft_atoi(argv[idx]);
        if (num == -1)
            processError("out of range");
        insertToContainers(num);
        idx++;
    }
    showStatusContainer("Before: ");
    FordJohnson();
    showStatusContainer("After: ");
    showTime();
}

void PmergeMe::FordJohnson()
{
    clock_t start, end;
    start = clock();
    vec = vec_mergeInsertionSort(vec);
    end = clock();
    _vecSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    start = clock();
    lst = lst_mergeInsertionSort(lst);
    end = clock();
    _lstSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}
