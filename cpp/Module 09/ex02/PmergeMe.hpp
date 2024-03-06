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
        double _vecSortTime;
        std::list<int> lst;
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

        void sortVector();
        void vec_bubbleSort(std::vector<int> &posVec);
        void vec_selectionSort(std::vector<int> &posVec);
        void vec_merge(std::vector<int> &posVec, int left, int mid, int right);
        void vec_mergeSort(std::vector<int>& posVec, int left, int right);

        void sortlist();
        void lst_merge(std::list<int> &posLst, std::list<int> &left, std::list<int> &right);
        void lst_mergeSort(std::list<int> &posLst);

        void showStatusContainer(const std::string &status);
        void showTime();
};

#endif