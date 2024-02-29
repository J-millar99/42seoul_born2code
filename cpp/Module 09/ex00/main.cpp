#include "BitcoinExchange.hpp"

bool checkFileValidity(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "could not identify the file." << std::endl;
        return false;
    }
    std::ifstream input(argv[1]);
    if (input.is_open())
    {
        input.close();
        return true;
    }
    else
    {
        std::cerr << "could not open file." << std::endl;
        return false;
    }
}

int main(int argc, char *argv[])
{
    if (!checkFileValidity(argc, argv))
        return 1;
    BitcoinExchange _BitcoinExchange;
    _BitcoinExchange.inputDB(argv[1]);
    return 0;
}