#include "span.hpp"

Span::Span(void): _size(0)
{
}

Span::Span(unsigned int n): _size(n)
{
}

Span::Span(Span const &src)
{
	this->_size = src.getSize(); 
	this->_arr = src.getArr();
}

Span::~Span(void)
{
}

Span &Span::operator=(Span const &rhs)
{
	this->_size = rhs.getSize();
	this->_arr = rhs.getArr();
	return (*this);
}

void	Span::addNumber(int n)
{
	if (_arr.size() < _size)
		_arr.push_back(n);
	else
		throw ArrayFullException();	
}

unsigned long int		Span::shortestSpan(void) const
{
	unsigned long int shortest = ULLONG_MAX;
	if (this->_arr.size() < 2)
		throw NotEnoughValuesException();
	unsigned long int tmp;	
	std::vector<int>::const_iterator it = _arr.begin();
	std::vector<int>::const_iterator it1;

	while (it != _arr.end() - 1)
	{
		it1  = it + 1;
		while (it1 != _arr.end())
		{
			tmp = abs(static_cast<long int>(*it) - static_cast<long int>(*it1)); 
			if (tmp < shortest)
				shortest = tmp;
			it1++;
		}
		it++;
	}
	return (shortest);
}

unsigned long int		Span::longestSpan(void) const
{
	if (this->_arr.size() < 2)
		throw NotEnoughValuesException();
	int biggest = *(std::max_element(_arr.begin(), _arr.end()));
	int smallest = *(std::min_element(_arr.begin(), _arr.end()));

	unsigned long int result = abs(static_cast<long int>(biggest) - static_cast<long int>(smallest));
	return (result);
}

const char* Span::ArrayFullException::what() const throw()
{
	return ("Can't add anymore values to Span");
}

const char* Span::NotEnoughValuesException::what() const throw()
{
	return ("Can't do a span with less than 2 values");
}




unsigned int	Span::getSize(void) const
{
	return (this->_size);
}

std::vector<int>	Span::getArr(void) const
{
	return (this->_arr);
}
