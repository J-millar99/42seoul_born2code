#include "BitcoinExchange.hpp"

void checkFileValidity(int argc, char *argv[])
{
    if (argc != 2)
        BitcoinExchange::processError("could not identify the file.");
    std::ifstream input(argv[1]);
    if (input.is_open())
        input.close();
    else
        BitcoinExchange::processError("could not open file.");
}

int main(int argc, char *argv[])
{
    checkFileValidity(argc, argv);
    BitcoinExchange _BitcoinExchange;
    _BitcoinExchange.inputDB(argv[1]);
    return 0;
}