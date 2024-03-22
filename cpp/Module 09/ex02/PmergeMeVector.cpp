#include "PmergeMe.hpp"
using namespace std;
int PmergeMe::Jacobsthal(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    return (Jacobsthal(num - 1) + 2 * Jacobsthal(num - 2));
}

void PmergeMe::GetJacobsthal(std::vector<int> &Jacob, size_t JacobSize)
{
    size_t idx, val;

    idx = 2;
    while ((val = Jacobsthal(idx)) <= JacobSize)
    {
        Jacob.push_back(val);
        ++idx;
    }
}

void PmergeMe::MargeInsertionSortVector(size_t pre_size)
{
    size_t size = pre_size * 2;
    size_t idx = 0;
    while (idx <= vec.size() - size)
    {
        if (vec[idx] < vec[idx + pre_size])
        {
            size_t jdx = 0;
            while (jdx < pre_size)
            {
                std::swap(vec[idx + jdx], vec[idx + pre_size + jdx]);
                jdx++;
            }
        }
        idx += size;
    }
    if (size * 2 <= vec.size())
        MargeInsertionSortVector(size);
    std::vector<int> MainChain;
    std::vector<int> SubChain;
    GroupMainSubChain(MainChain, SubChain, pre_size);
    std::vector<int> Jacob;
    GetJacobsthal(Jacob, SubChain.size() / pre_size);
    show(MainChain, "그룹m");
    show(SubChain, "그룹s");
    show(vec, "그룹v");
    cout << "++++++++++++++++++++++++\n";
    BinarySearchInsertion(MainChain, SubChain, Jacob, pre_size);
    std::copy(MainChain.begin(), MainChain.end(), vec.begin());
    show(MainChain, "최종m");
    show(SubChain, "최종s");
    show(vec, "최종v");
    cout << "========================\n";
}

void PmergeMe::GroupMainSubChain(std::vector<int> &MainChain, std::vector<int> &SubChain, size_t pre_size)
{
    size_t size = pre_size * 2;
    size_t idx = 0;

    while (idx < vec.size() / size * size)
    {
        MainChain.insert(MainChain.end(), vec.begin() + idx, vec.begin() + idx + pre_size);
        SubChain.insert(SubChain.end(), vec.begin() + idx + pre_size, vec.begin() + idx + size);
        idx += size;
    }

    if (vec.size() - idx >= pre_size)
        SubChain.insert(SubChain.end(), vec.begin() + idx, vec.begin() + idx + pre_size);
}

int PmergeMe::GetJacobsthalLimit(std::vector<int> Jacob, size_t idx)
{
    int limit = 0;
    int start = 2;

    if (Jacob.size() == 1)
        return 0;
    while ((limit = Jacobsthal(start)) < Jacob[idx])
        start++;
    if (limit == 1)
        return 0;
    return Jacobsthal(start - 1);
}

int PmergeMe::BinarySearch(std::vector<int> MainChain, int target, size_t size)
{
    size_t left = 0;
    size_t right = (MainChain.size() / size) - 1;
    size_t mid;
    
    if (right == 0)
        return 0;
    while (right > left)
    {
        mid = left + (right - left) / 2;
        if (target > MainChain[mid * size]) //타킷이 큼
            left = mid + 1;
        else // 타깃이 작음
            right = mid;
    }
    return left * size;
}

void PmergeMe::BinarySearchInsertion(std::vector<int> &MainChain, std::vector<int> &SubChain, std::vector<int> &Jacob, size_t pre_size)
{
    size_t idx = 0;
    int found;
    size_t cnt = 0;
    while (idx < Jacob.size())
    {
        int limit = GetJacobsthalLimit(Jacob, idx);
        while (limit < Jacob[idx])
        {
            found = BinarySearch(MainChain, SubChain[(Jacob[idx] - 1 - cnt) * pre_size], pre_size);
            MainChain.insert(MainChain.begin() + found, SubChain.begin() + (Jacob[idx] - 1 - cnt) * pre_size, SubChain.begin() + (Jacob[idx] - 1 - cnt) * pre_size + pre_size);
            SubChain.erase(SubChain.begin() + (Jacob[idx] - 1 - cnt) * pre_size, SubChain.begin() + (Jacob[idx] - 1 - cnt) * pre_size + pre_size);
            cnt++;
            Jacob[idx]--;
        }
        idx++;
    }
    while (SubChain.size())
    {
        found = BinarySearch(MainChain, *(SubChain.end() - pre_size), pre_size);
        MainChain.insert(MainChain.begin() + found, SubChain.end() - pre_size, SubChain.end());
        SubChain.erase(SubChain.end() - pre_size, SubChain.end());
    }
}