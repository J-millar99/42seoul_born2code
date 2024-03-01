#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

/*
    1. Ford-Johnson algorithm.
    2. at least two different containers & at least 3000 different integers.
    3. mandatory : avoid generic function, implement your algorithm
    4. 
*/

class PmergeMe
{
    private:

    public:
        static bool checkArgumentsValidity(int argc, char *argv[]);
        static bool isDecimal(const std::string token);
        static void processError(const std::string &errorStr);
};

#endif