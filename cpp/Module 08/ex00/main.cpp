#include "easyfind.hpp"

int main()
{
    // You don’t have to handle associative containers.
    // Map, Set: key, value
    // Vector, List: index
    int inum = -1; // finding number
    try
    {
        int arr[] = {1, 2, 3, 3, 4};
        std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
        std::vector<int>::iterator result = easyfind(vec, inum);
        std::cout << "Value found in vector at index: " << std::distance(vec.begin(), result) << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << "(vector)" << std::endl;
    }
    try
    {
        int arr[] = {1, 2, 3, 3, 4};
        std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
        std::list<int>::iterator result = easyfind(lst, inum);
        std::cout << "Value found in list at index: " << std::distance(lst.begin(), result) << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << "(list)" << std::endl;
    }
    return 0;
}