void PmergeMe::Marge_Insertion_Vector(size_t pre_size)
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
        Marge_Insertion_Vector(size);
    idx = 0;
    std::vector<int> MainChain;
    std::vector<int> SubChain;
    while (idx < vec.size() / size * size)
    {
        MainChain.insert(MainChain.end(), vec.begin() + idx, vec.begin() + idx + pre_size);
        SubChain.insert(SubChain.end(), vec.begin() + idx + pre_size, vec.begin() + idx + pre_size * 2);
        idx += size;
    }

    if (vec.size() - idx >= pre_size)
        SubChain.insert(SubChain.end(), vec.begin() + idx, vec.begin() + idx + pre_size);

    int subSize, acob_idx, acob_jdx;
    std::vector<int> _jacobSequence;
    subSize = SubChain.size() / pre_size;
    acob_idx = 2;
    while ((acob_jdx = jacobsthal(acob_idx)) <= subSize)
    {
        _jacobSequence.push_back(acob_jdx);
        ++acob_idx;
    }
    show(_jacobSequence, "야콥 배열");
    size_t jdx = 0;
    while (jdx < _jacobSequence.size())
    {
        int jacobLimit = 0;
        int start = 2;
        while (_jacobSequence.size() != 1 && (jacobLimit = jacobsthal(start)) < _jacobSequence[jdx])
            start++;
        while (jacobLimit < _jacobSequence[jdx])
        {
            for (int kdx = 0; kdx * pre_size < MainChain.size(); kdx++)
            {
                if (SubChain[(_jacobSequence[jdx] - 1) * pre_size] < MainChain[kdx * pre_size])
                {
                    MainChain.insert(MainChain.begin() + kdx * pre_size, SubChain.begin() + (_jacobSequence[jdx] - 1) * pre_size, SubChain.begin() + (_jacobSequence[jdx] - 1) * pre_size + pre_size);
                    SubChain.erase(SubChain.begin() + (_jacobSequence[jdx] - 1) * pre_size, SubChain.begin() + (_jacobSequence[jdx] - 1) * pre_size + pre_size);
                    break;
                }
            }
            _jacobSequence[jdx]--;
        }
        jdx++;
    }
    while (SubChain.size())
    {
        for (int kdx = 0; kdx * pre_size < MainChain.size(); kdx++)
        {
            if (SubChain[SubChain.size() - pre_size] < MainChain[kdx * pre_size])
            {
                MainChain.insert(MainChain.begin() + kdx * pre_size, SubChain.end() - pre_size, SubChain.end());
                SubChain.erase(SubChain.end() - pre_size, SubChain.end());
                break;
            }
        }
    }
    std::copy(MainChain.begin(), MainChain.end(), vec.begin());
}
