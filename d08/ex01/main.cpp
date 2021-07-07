#include "span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	sp.addNumber(2147483647);
	sp.addNumber(-2147483648);
	sp.addNumber(1);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(4);
		std::cout << "ne devrait pas s'afficher" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span newtest = Span(5);
	std::vector<int> myvec;

	for (int i = 0; i < 6; i++)
		myvec.push_back(i);

	try 
	{
		newtest.addVec(myvec);
	}
	catch (std::exception &e)
	{
		std::cout << "last test " << e.what() << std::endl;
	}
	std::cout << newtest.shortestSpan() << std::endl;
	std::cout << newtest.longestSpan() << std::endl;

}
