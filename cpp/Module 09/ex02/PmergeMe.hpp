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
    
        void FordJohnson();

        void mergeInsertSortVector(std::vector<int> &vector, int start, int end);
        void mergeSortVector(std::vector<int> &vector, int start, int mid, int end);
        void insertSortVector(std::vector<int> &vector, int start, int end);

        void mergeInsertSortList(std::list<int>::iterator start, std::list<int>::iterator end);
        void mergeSortList(std::list<int>::iterator start, std::list<int>::iterator mid, std::list<int>::iterator end);
        void insertSortList(std::list<int>::iterator start, std::list<int>::iterator end);

        void showStatusContainer(const std::string &status);
        void showTime();
};

#endif