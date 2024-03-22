#include "PmergeMe.hpp"

// Recursive function that sorts a list using the merge-insertion sort algorithm
void PmergeMe::mergeInsertionSort(std::list<int> &_lst)
{
    // Base case: if the _lst has 1 or 0 elements, it is already sorted
    if (_lst.size() <= 1) {
        return;
    }

    // Divide the _lst into two halves
    std::list<int> left, right;
    int middle = _lst.size() / 2;
    for (std::list<int>::iterator it = _lst.begin(); it != _lst.end(); ++it) {
        // Add each element to the left or right half depending on its position
        if (std::distance(_lst.begin(), it) < middle) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
    }

    // Sort the left and right halves recursively
    mergeInsertionSort(left);
    mergeInsertionSort(right);

    // Clear the input _lst to merge the two halves
    _lst.clear();

    // Merge the two sorted halves
    std::list<int>::iterator it_left = left.begin();
    std::list<int>::iterator it_right = right.begin();
    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left < *it_right) {
            _lst.push_back(*it_left);
            ++it_left;
        } else {
            _lst.push_back(*it_right);
            ++it_right;
        }
    }

    // Append any remaining elements from the left or right halves
    while (it_left != left.end()) {
        _lst.push_back(*it_left);
        ++it_left;
    }

    while (it_right != right.end()) {
        _lst.push_back(*it_right);
        ++it_right;
    }
}