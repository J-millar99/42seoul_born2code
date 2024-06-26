#include "PmergeMe.hpp"

int PmergeMe::vec_binarySearch(std::vector<int> &_vec, int target)
{
    int low = 0;
    int high = _vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (_vec[mid] == target)
            return mid;
        else if (_vec[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

std::vector<int> PmergeMe::vec_mergeInsertionSort(std::vector<int> X)
 {
    int n = X.size();
    if (n <= 1) {
        return X;
    }
    std::vector<int> S;
    for (int i = 0; i < n - 1; i += 2) {
        if (X[i] > X[i + 1]) {
            S.push_back(X[i]);
            X[i] = X[i + 1];
        } else {
            S.push_back(X[i + 1]);
        }
    }
    if (n % 2 != 0)
        S.push_back(X[n - 1]);
    S = vec_mergeInsertionSort(S);
    std::vector<int> result;
    result.push_back(X[0]);
    for (int i = 1; i < n; ++i) {
        int index = vec_binarySearch(S, X[i]);
        S.insert(S.begin() + index, X[i]);
    }
    return S;
}
