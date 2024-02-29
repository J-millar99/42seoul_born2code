#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        MutantStack();
        MutantStack(const MutantStack &ref);
        MutantStack &operator=(const MutantStack &ref);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin();
        iterator end();
};

# include "MutantStack.tpp"

#endif
