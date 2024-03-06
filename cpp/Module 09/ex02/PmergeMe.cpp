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

void PmergeMe::processError(const std::string &errorStr)
{
    std::cerr << errorStr << std::endl;
    exit(1);
}

void PmergeMe::isDecimal(const std::string token)
{
    if (token.size() == 0)
        processError("Argument Error");
    for (size_t idx = 0; idx < token.length(); ++idx)
        if (!isdigit(token[idx]))
            processError("\"" + token + "\" is not a positive number");
}

void PmergeMe::checkArgumentsValidity(int argc, char *argv[])
{
    if (argc == 1)
        processError("Argument Error");
    for (int idx = 1; idx < argc; ++idx)
        isDecimal(argv[idx]);
}

int PmergeMe::ft_atoi(const std::string &str)
{
    long inum = 0;
    size_t idx = 0;

    while (isdigit(str[idx]))
    {
        inum *= 10;
        inum += str[idx] - '0';
        if (inum > INT_MAX || inum < INT_MIN)
            return -1;
        ++idx;
    }
    return static_cast<int>(inum);
}

void PmergeMe::insertToContainers(int value)
{
    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), value);
    if (it == vec.end())
    {
        vec.push_back(value);
        lst.push_back(value);
    }
    else
        processError("duplicated number");
}

void PmergeMe::showStatusContainer(const std::string &status)
{
    std::cout << status;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::showTime()
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout   << "Time to process a range of " \
                << vec.size() \
                << " elements with std::vector : " \
                << _vecSortTime
                << " us\n";
    std::cout   << "Time to process a range of " \
                << lst.size() \
                << " elements with std::list : " \
                << _lstSortTime
                << " us\n";
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

void PmergeMe::vec_bubbleSort(std::vector<int> &posVec)
{
    int n = posVec.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i)
        {
            if (posVec[i] > posVec[i + 1])
            {
                std::swap(posVec[i], posVec[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void PmergeMe::vec_selectionSort(std::vector<int> &posVec)
{
    int n = posVec.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if (posVec[j] < posVec[minIndex])
                minIndex = j;
        if (minIndex != i) 
            std::swap(posVec[i], posVec[minIndex]);
    }
}

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

void PmergeMe::sortVector()
{
    int n = vec.size();
    std::vector<int> posVec;
    for (int i = 0; i < n; ++i)
        if (vec[i] > 0)
            posVec.push_back(vec[i]);
    vec_mergeSort(posVec, 0, posVec.size() - 1);
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (vec[i] > 0)
        {
            vec[i] = posVec[j];
            ++j;
        }
    }
}

void PmergeMe::lst_merge(std::list<int> &posLst, std::list<int> &left, std::list<int> &right)
{
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end())
    {
        if (*leftIt <= *rightIt)
        {
            posLst.push_back(*leftIt);
            ++leftIt;
        }
        else
        {
            posLst.push_back(*rightIt);
            ++rightIt;
        }
    }
    while (leftIt != left.end())
    {
        posLst.push_back(*leftIt);
        ++leftIt;
    }
    while (rightIt != right.end())
    {
        posLst.push_back(*rightIt);
        ++rightIt;
    }
}

void PmergeMe::lst_mergeSort(std::list<int> &posLst)
{
    if (posLst.size() <= 1)
        return;
    std::list<int> left, right;
    int middle = posLst.size() / 2;
    std::list<int>::iterator it = posLst.begin();
    for (int i = 0; i < middle; ++i)
    {
        left.push_back(*it);
        ++it;
    }
    for (size_t i = middle; i < posLst.size(); ++i)
    {
        right.push_back(*it);
        ++it;
    }
    lst_mergeSort(left);
    lst_mergeSort(right);
    posLst.clear();
    lst_merge(posLst, left, right);
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