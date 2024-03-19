#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char *argv[])
{
    int i = 1, j = 0;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while (argv[i])
    {
        int len = strlen(argv[i]);
        j = 0;
        while (j < len)
        {
            if (islower(argv[i][j]))
                argv[i][j] -= 'a' - 'A';
            std::cout << argv[i][j];
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return 0;
}