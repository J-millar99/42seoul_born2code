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

void replaceFileName(std::string filename)
{
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) 
	{
		std::ofstream outputFile(replaceExtension(filename));
		if (!outputFile.is_open())
		{
			std::cerr << "Error: Failed to open output file." << std::endl;
			inputFile.close();
			return ;
		}
		char currentChar;

		while (inputFile.get(currentChar))
		{
			if (currentChar == '\n')
				outputFile << std::endl;
			else
				outputFile << currentChar;
		}
		inputFile.close();
		outputFile.close();
    }
	else
		std::cout << "Error: Failed to open output file." << std::endl;
}