#include "PmergeMe.hpp"

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

    BinarySearchInsertion(MainChain, SubChain, Jacob, pre_size);
    std::copy(MainChain.begin(), MainChain.end(), vec.begin());
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

int PmergeMe::GetJacobsthalLimit(std::vector<int> &Jacob, size_t idx)
{
    int jacobLimit = 0;
    int start = 2;

    if (Jacob.size() == 1)
        return 0;
    while ((jacobLimit = Jacobsthal(start)) < Jacob[idx])
        start++;
    return jacobLimit;
}

void PmergeMe::BinarySearchInsertion(std::vector<int> &MainChain, std::vector<int> &SubChain, std::vector<int> &Jacob, size_t pre_size)
{
    size_t idx = 0;
    while (idx < Jacob.size())
    {
        int jacobLimit = GetJacobsthalLimit(Jacob, idx);
        while (jacobLimit < Jacob[idx])
        {
            for (int jdx = 0; jdx * pre_size < MainChain.size(); jdx++)
            {
                if (SubChain[(Jacob[idx] - 1) * pre_size] < MainChain[jdx * pre_size])
                {
                    MainChain.insert(MainChain.begin() + jdx * pre_size, SubChain.begin() + (Jacob[idx] - 1) * pre_size, SubChain.begin() + (Jacob[idx] - 1) * pre_size + pre_size);
                    SubChain.erase(SubChain.begin() + (Jacob[idx] - 1) * pre_size, SubChain.begin() + (Jacob[idx] - 1) * pre_size + pre_size);
                    break;
                }
            }
            Jacob[idx]--;
        }
        idx++;
    }
    while (SubChain.size())
    {
        for (int jdx = 0; jdx * pre_size < MainChain.size(); jdx++)
        {
            if (SubChain[SubChain.size() - pre_size] < MainChain[jdx * pre_size])
            {
                MainChain.insert(MainChain.begin() + jdx * pre_size, SubChain.end() - pre_size, SubChain.end());
                SubChain.erase(SubChain.end() - pre_size, SubChain.end());
                break;
            }
        }
    }
}