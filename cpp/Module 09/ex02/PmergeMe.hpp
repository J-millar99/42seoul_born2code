#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>

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
    
        void FordJohnson();
    
        int vec_binarySearch(std::vector<int> &_vec, int target);
        std::vector<int> vec_mergeInsertionSort(std::vector<int> X);

        std::list<int>::iterator lst_binarySearch(std::list<int> &_lst, int key);
        std::list<int> lst_mergeInsertionSort(std::list<int> &X);

        void showStatusContainer(const std::string &status);
        void showTime();
};

#endif