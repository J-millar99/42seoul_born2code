#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define INITSIZE 2
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
        //  OCF
        PmergeMe();
        PmergeMe(const PmergeMe &ref);
        PmergeMe &operator=(const PmergeMe &ref);

        //  Time
        double _vecSortTime;
        double _lstSortTime;
    
        std::vector<int> vec;
        std::list<int> lst;

    public:
        //  OCF
        PmergeMe(char *argv[]);
        ~PmergeMe();

        //  Check Utils
        static void CheckArgumentsValidity(int argc, char *argv[]);
        static void IsDecimal(const std::string token);
        static void ProcessError(const std::string &errorStr);

        //  Utils
        int ft_atoi(const std::string &str);
        void InsertToContainers(int value);
        void ShowStatusContainer(const std::string &status);
        void ShowTime();

        //  Algorithm
        void FordJohnsonAlgorithm();
        //  Vector
        void MargeInsertionSortVector(size_t pre_size);
        int Jacobsthal(int num);
        void GetJacobsthal(std::vector<int> &Jacob, size_t JacobSize);
        void GroupMainSubChain(std::vector<int> &MainChain, std::vector<int> &SubChain, size_t pre_size);
        void BinarySearchInsertion(std::vector<int> &MainChain, std::vector<int> &SubChain, std::vector<int> &Jacob, size_t pre_size);
        int GetJacobsthalLimit(std::vector<int> &Jacob, size_t idx);
        //  List

        //  List Jacobsthal
        void show(std::vector<int> _vec, std::string _name);
};

#endif