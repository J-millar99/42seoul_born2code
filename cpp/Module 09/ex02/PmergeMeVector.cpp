#include "PmergeMe.hpp"
void PmergeMe::mergeInsertionSort(std::vector<int> &_vec)
{
    // Base case: if the _vec has 1 or 0 elements, it is already sorted
    if (_vec.size() <= 1) {
        return;
    }

    // Divide the _vec into two halves
    int middle = _vec.size() / 2;
    std::vector<int> left(_vec.begin(), _vec.begin() + middle);
    std::vector<int> right(_vec.begin() + middle, _vec.end());

    // Sort the left and right halves recursively
    mergeInsertionSort(left);
    mergeInsertionSort(right);

    // Merge the two sorted halves into one sorted _vec
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < static_cast<int>(left.size()) && j < static_cast<int>(right.size())) {
        if (left[i] < right[j]) {
            _vec[k++] = left[i++];
        } else {
            _vec[k++] = right[j++];
        }
    }

    while (i < static_cast<int>(left.size())) {
        _vec[k++] = left[i++];
    }

    while (j < static_cast<int>(right.size())) {
        _vec[k++] = right[j++];
    }
}
