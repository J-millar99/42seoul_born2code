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
    sortVector();
    end = clock();
    _vecSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    start = clock();
    sortlist();
    end = clock();
    _lstSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::sortVector()
{
    // int n = vec.size();
    std::vector<int> posVec(vec);
    // for (int i = 0; i < n; ++i)
    //     if (vec[i] > 0)
    //         posVec.push_back(vec[i]);
    vec_mergeSort(posVec, 0, posVec.size() - 1);
    int j = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] > 0)
        {
            vec[i] = posVec[j];
            ++j;
        }
    }
}

void PmergeMe::sortlist()
{
    std::list<int> posList;
    
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        if (*it > 0)
            posList.push_back(*it);
    lst_mergeSort(posList);
    lst.clear();
    for (std::list<int>::iterator it = posList.begin(); it != posList.end(); ++it)
        lst.push_back(*it);
}