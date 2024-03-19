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
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

        iterator begin();
        reverse_iterator rbegin();
        iterator end();
        reverse_iterator rend();

};

# include "MutantStack.tpp"

#endif
