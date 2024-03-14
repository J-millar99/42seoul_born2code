#include "PmergeMe.hpp"

void PmergeMe::processError(const std::string &errorStr)
{
    std::cerr << errorStr << std::endl;
    std::exit(1);
}

void PmergeMe::isDecimal(const std::string token)
{
    if (token.size() == 0)
        processError("Argument Error");
    for (size_t idx = 0; idx < token.length(); ++idx)
        if (!std::isdigit(token[idx]))
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

    while (std::isdigit(str[idx]))
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
