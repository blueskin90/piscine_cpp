#include "ex04.hpp"

static bool	parseNumber(std::string::iterator *it, std::vector<Token*> *list)
{
	std::string str;
	int			value;
	while (**it && isNumber(**it))
	{
		str.append(1, **it);
		(*it)++;
	}
	try
	{
		value = std::stoi(str, NULL, 10);
		list->push_back(new NumToken(value));
	}
	catch (std::exception &e)
	{
		std::cout << "Couldn't parse " << str << " because : " << e.what() << std::endl;
		return (false);
	}
	return (true);
}

static bool	parseSignedNumber(std::string::iterator *it, std::vector<Token*> *list)
{
	std::string str;
	int			value;

	str.append(1, **it);
	(*it)++;
	while (**it && isNumber(**it))
	{
		str.append(1, **it);
		(*it)++;
	}
	try
	{
		value = std::stoi(str, NULL, 10);
		list->push_back(new NumToken(value));
	}
	catch (std::exception &e)
	{
		std::cout << "Couldn't parse " << str << " because : " << e.what() << std::endl;
		return (false);
	}
	return (true);
}


static bool	parseSign(std::string::iterator *it, std::vector<Token*> *list)
{
	if ((**it == '+' || **it == '-') && isNumber(*((*it) + 1)))
		return (parseSignedNumber(it, list));
	list->push_back(new OpToken(**it));
	(*it)++;
	return (true);
}

static void	parsePar(std::string::iterator *it, std::vector<Token*> *list)
{
	if (**it == '(')
		list->push_back(new ParOpenToken(**it));
	else
		list->push_back(new ParCloseToken(**it));
	(*it)++;
}

bool	tokenizeString(const char *charstr, std::vector<Token*> *list)
{
	std::string str(charstr);

	for (std::string::iterator it = str.begin(); it != str.end(); )
	{
		if (isSign(*it))
		{
			if (!parseSign(&it, list))
				return (false);
		}
		else if (isNumber(*it))
		{
			if (!parseNumber(&it, list))
				return (false);
		}
		else if (isPar(*it))
			parsePar(&it, list);
		else if (*it == ' ')
			++it;
		else
		{
			std::cout << "Can't parse token: " << *it << std::endl;
			return (false);
		}
	}
	return (true);
}
