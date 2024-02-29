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

int BitcoinExchange::ft_atoi(const std::string &str)
{
    long inum = 0;
    size_t idx = 0;

    if (!str[0])
        return 0;
    while (isdigit(str[idx]))
    {
        inum *= 10;
        inum += str[idx] - '0';
        if (inum > INT_MAX || inum < INT_MIN)
            return -1;
        ++idx;
    }
    if (str[idx])
        return 0;
    return static_cast<int>(inum);
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::checkDayValidity(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
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
    size_t first = keyStr.find_first_not_of(" \t0");
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
    while (isdigit(valueStr[idx]))
        ++idx;
    if ((valueStr[idx] == '.'))
        ++idx;
    while (isdigit(valueStr[idx]))
        ++idx;
    if (valueStr[idx])
        return false;
    return true;
}

void BitcoinExchange::setDB()
{
    std::string fileName = "data.csv";
    std::ifstream dataFile(fileName.c_str());
    std::string line;

    if (!dataFile.is_open())
    {
        std::cerr << "could not connect database" << std::endl;
        exit(1);
    }
    while (std::getline(dataFile, line))
    {
        if (!line[0] || !strcmp(line.c_str(), "date,exchange_rate"))
            continue;
        std::istringstream iss(line);
        std::string dataKey;
        std::string dataValue;
        if (std::getline(iss, dataKey, ',') && iss >> dataValue)
        {
            if (checkKeyValidity(dataKey) && checkValueValidity(dataValue))
            {
                float fnum = std::atof(dataValue.c_str());
                if (!(fnum < 0 || fnum > 1000))
                    database[dataKey] = fnum;
            }
        }
    }
    dataFile.close();
}

void BitcoinExchange::inputDB(std::string fileName)
{
    std::ifstream inputFile(fileName.c_str());
    std::string line;

    if (!inputFile.is_open())
    {
        std::cerr << "could not connect database" << std::endl;
        exit(1);
    }
    while (std::getline(inputFile, line))
    {
        if (!line[0] || !strcmp(line.c_str(), "date | value"))
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