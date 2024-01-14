#include "String.hpp"

static std::string replaceExtension(const std::string &filename) 
{
    size_t lastDotPos = filename.find_last_of(".");
    
    if (lastDotPos != std::string::npos)
	{
        std::string baseName = filename.substr(0, lastDotPos);
        return baseName + ".replace";
    }
	else
        return filename + ".replace";
}

static std::string &replaceLine(t_String sed, std::string &line)
{
	size_t found = 0;
	while ((found = line.find(sed.s1, found)) != std::string::npos)
	{
		line = line.substr(0, found) + sed.s2 + line.substr(found + sed.s1.length());
		found += sed.s2.length() - 1;
	}
	return (line);
}

static void printLine(t_String sed, std::ifstream &inputFile, std::ofstream &outputFile)
{
	char ch;
	std::string line;

	while (inputFile.get(ch))
	{
		line += ch;
		if (ch == '\n')
		{
			line = replaceLine(sed, line);
			outputFile << line;
			line = "\0";
		}
	}
	outputFile << replaceLine(sed, line);
	inputFile.close();
	outputFile.close();
}

void replaceFile(t_String sed)
{
    std::ifstream inputFile(sed.fileName.c_str());

    if (inputFile.is_open()) 
	{
		std::ofstream outputFile(replaceExtension(sed.fileName).c_str());
		if (!outputFile.is_open())
		{
			std::cerr << "Error: Failed to open output file." << std::endl;
			inputFile.close();
			return ;
		}
		printLine(sed, inputFile, outputFile);
    }
	else
		std::cout << "Error: Failed to open output file." << std::endl;
}