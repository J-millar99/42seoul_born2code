#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::list<int> lst;
        double _vecSortTime;
        double _lstSortTime;
        PmergeMe();
        PmergeMe(const PmergeMe &ref);
        PmergeMe &operator=(const PmergeMe &ref);

    public:
        PmergeMe(char *argv[]);
        ~PmergeMe();
        static void checkArgumentsValidity(int argc, char *argv[]);
        static void isDecimal(const std::string token);
        static void processError(const std::string &errorStr);

        int ft_atoi(const std::string &str);
        void insertToContainers(int value);
        void mergeInsertionSort(std::vector<int> &_vec);
        void mergeInsertionSort(std::list<int> &_lst);
        void FordJohnson();
        void showStatusContainer(const std::string &status);
        void showTime();
};

#endif