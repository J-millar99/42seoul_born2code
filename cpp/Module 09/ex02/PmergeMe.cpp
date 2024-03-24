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
            ProcessError("out of range");
        InsertToContainers(num);
        idx++;
    }
    ShowStatusContainer("====== Before ======");
    FordJohnsonAlgorithm();
    ShowStatusContainer("====== After ======");
    ShowTime();
}

void PmergeMe::FordJohnsonAlgorithm()
{
    clock_t start, end;
    start = clock();
    MergeInsertionSortVector(INITSIZE);
    end = clock();
    _vecSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    start = clock();
    MergeInsertionSortList(INITSIZE);
    end = clock();
    _lstSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}
