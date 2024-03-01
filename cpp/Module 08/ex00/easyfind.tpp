#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it != container.end())
        return it;
    else
        throw std::out_of_range("Value not found in container");
}

template <typename T>
typename T::iterator easyfind(const T &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it != container.end())
        return it;
    else
        throw std::out_of_range("Value not found in const container");
}

#endif
