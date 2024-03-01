#include "PmergeMe.hpp"

void PmergeMe::processError(const std::string &errorStr)
{
    std::cerr << errorStr << std::endl;
}

bool PmergeMe::isDecimal(const std::string token)
{
    for (size_t idx = 0; idx < token.length(); ++idx)
    {
        if (!isdigit(token[idx]))
        {
            processError("\"" + token + "\" is not a positive number");
            return false;
        }
    }
    return true;
}

bool PmergeMe::checkArgumentsValidity(int argc, char *argv[])
{
    if (argc == 1)
        return false;
    for (size_t idx = 1; idx < argc; ++idx)
        if (!isDecimal(argv[idx]))
            return false;
    return true;
}