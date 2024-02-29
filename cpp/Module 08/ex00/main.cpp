#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    // You don’t have to handle associative containers.
    // Sequence container(index) : vector, list, deque, string, queue, stack, array(C++11)
    // Associative container(key - value) : map, set, unordered_map, unordered_set

    int inum = 3; // finding number
    int arr[] = {1, 2, 3, 3, 4};
    try
    {
        std::vector<int> vector(arr, arr + sizeof(arr) / sizeof(arr[0]));
        std::vector<int>::iterator result = easyfind(vector, inum);
        std::cout << "Value found in vector at index: " << std::distance(vector.begin(), result) << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << "(vector)" << std::endl;
    }

    try
    {
        std::list<int> list(arr, arr + sizeof(arr) / sizeof(arr[0]));
        std::list<int>::iterator result = easyfind(list, inum);
        std::cout << "Value found in list at index: " << std::distance(list.begin(), result) << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << "(list)" << std::endl;
    }

    try
    {
        std::deque<int> deque(arr, arr + sizeof(arr) / sizeof(arr[0]));
        std::deque<int>::iterator result = easyfind(deque, inum);
        std::cout << "Value found in deque at index: " << std::distance(deque.begin(), result) << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << "(deque)" << std::endl;
    }
    return 0;
}