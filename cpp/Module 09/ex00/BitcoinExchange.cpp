#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange() { setDB(); }
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) { database = ref.database; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
    if (this != &ref)
        database = ref.database;
    return *this;
}

bool BitcoinExchange::checkDayValidity(int year, int month, int day)
{
    if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 2) {
        if (isLeapYear(year) && day > 29)
            return false;
        if (!isLeapYear(year) && day > 28)
            return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    return true;  
}

bool BitcoinExchange::checkKeyValidity(std::string &keyStr)
{
    size_t first = keyStr.find_first_not_of(" \t");
    size_t last = keyStr.find_last_not_of(" \t");
    size_t count = std::count(keyStr.begin(), keyStr.end(), '-');
    if (count != 2)
        return false;
    if (first != std::string::npos)
        keyStr = keyStr.substr(first, (last-first+1));
    std::istringstream iss(keyStr);
    std::string token;

    int year, month, day;

    std::getline(iss, token, '-');
    if (token.length() < 4)
        return false;
    year = ft_atoi(token);

    std::getline(iss, token, '-');
    if (token.length() != 2)
        return false;
    month = ft_atoi(token);

    std::getline(iss, token, '-');
    if (token.length() != 2)
        return false;
    day = ft_atoi(token);

    return checkDayValidity(year, month, day) ? true : false;
}

bool BitcoinExchange::checkValueValidity(const std::string &valueStr)
{
    size_t idx = 0;

    if (!valueStr[0])
        return false;
    while (std::isdigit(valueStr[idx]))
        ++idx;
    if ((valueStr[idx] == '.'))
        ++idx;
    while (std::isdigit(valueStr[idx]))
        ++idx;
    if (valueStr[idx])
        return false;
    return true;
}

void BitcoinExchange::setDB()
{
    std::ifstream dataFile("data.csv");
    std::string line;

    if (!dataFile.is_open())
        processError("could not connect database");
    std::getline(dataFile, line);
    while (std::getline(dataFile, line))
    {
        std::istringstream iss(line);
        std::string dataKey;
        std::string dataValue;
        if (std::getline(iss, dataKey, ',') && iss >> dataValue)
        {
            float fnum = std::atof(dataValue.c_str()); 
            database[dataKey] = fnum;
        }
    }
    dataFile.close();
}

void BitcoinExchange::inputDB(std::string fileName)
{
    std::ifstream inputFile(fileName.c_str());
    std::string line;

    if (!inputFile.is_open())
        processError("could not connect input database");
    std::getline(inputFile, line);
    if (std::strcmp(line.c_str(), "date | value"))
        processError("wrong database format");
    while (std::getline(inputFile, line))
    {
        if (!line[0])
            continue;
        std::istringstream iss(line);
        std::string dataKey;
        std::string dataValue;
        if (std::getline(iss, dataKey, '|') && iss >> dataValue)
        {
            if (!checkKeyValidity(dataKey))
                std::cerr << "Error: impossible date => " << dataKey << std::endl;
            else if (!checkValueValidity(dataValue) || std::atof(dataValue.c_str()) < 0)
                std::cerr << "Error: not a positive number => " << dataValue << std::endl;
            else if (ft_atoi(dataValue.c_str()) == -1)
                std::cerr << "Error: too large a number => " << dataValue << std::endl;
            else
                calcRate(dataKey, dataValue);
        }
        else
            std::cerr << "Error: bad input => " << line << std::endl;
    }
}

void BitcoinExchange::calcRate(const std::string &dataKey, const std::string &dataValue)
{
    float fmul = std::atof(dataValue.c_str());
    if ((fmul < 0 || fmul > 1000))
    {
        std::cerr << "out of range (0 to 1000)" << std::endl;
        return ;
    }
    std::map<std::string, float>::iterator it = database.find(dataKey);
    if (it == database.end())
    {
        std::map<std::string, float> temp_db = database;
        temp_db[dataKey] = 0;
        std::map<std::string, float>::iterator temp_it = temp_db.find(dataKey);
        if (temp_it != temp_db.begin())
        {
            --temp_it;
            std::cout << dataKey << " => " << dataValue << " = " << temp_it->second * fmul << std::endl;
        }
        else
            std::cerr << "impossible calculation => " << dataKey << std::endl;
    }
    else
        std::cout << dataKey << " => " << dataValue << " = " << database[dataKey] * fmul << std::endl;

}