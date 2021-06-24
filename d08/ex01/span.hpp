#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span{
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);
		Span &operator = (Span const &rhs);

		void addNumber(int n);
		unsigned long int	shortestSpan(void) const;
		unsigned long int longestSpan(void) const;

		unsigned int getSize(void) const;
		std::vector<int> getArr(void) const;

		class ArrayFullException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughValuesException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		unsigned int _size;
		std::vector<int> _arr;

};

#endif /* SPAN_HPP */
