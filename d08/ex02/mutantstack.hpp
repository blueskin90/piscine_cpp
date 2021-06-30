#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) { return (std::begin(std::stack<T>::c)); };
		iterator end(void) { return (std::end(std::stack<T>::c)); };
};

#endif /* MUTANTSTACK_HPP */
