#include "Converter.hpp"

//public 

Converter::Converter(std::string param): _string(param) 
{
	convert();
}

Converter::~Converter(void)
{
	// to delete after
	this->_f_value = 0;
	this->_c_value = '1';
	this->_i_value = 0;
}

std::string Converter::getString(void) const
{
	return (this->_string);
}

// private

Converter::Converter(Converter const &src): _string(src.getString())
{
	convert();
}

Converter &Converter::operator=(Converter const &rhs)
{
	this->_string = rhs.getString();
	convert();
	return (*this);
}

Converter::Converter(void)
{
	this->_string = "Stop making us do Coplien class when it's useless.";
}

void	Converter::convert(void)
{
	double value;

	try {
		value = std::stod(this->_string, NULL);
		this->_d_value = value;
		this->_f_value = static_cast<float>(value);
		this->_i_value = static_cast<int>(value);
		this->_c_value = static_cast<char>(value);
	}
	catch (std::exception &e)
	{
		this->_c_value = _string[0];
		this->_i_value = static_cast<int>(_string[0]);
		this->_f_value = static_cast<float>(_i_value);
		this->_d_value = static_cast<double>(_f_value);
	}
}

void Converter::printFloat(void) const
{
	std::cout << "float: " << std::setprecision(1) << std::fixed <<  _f_value << "f" << std::endl;
}

void Converter::printDouble(void) const
{
	std::cout << "double: " << std::setprecision(1) << std::fixed << _d_value << std::endl;
}

void Converter::printChar(void) const
{
	std::string printvalue;
	if (std::isfinite(_f_value))
		printvalue = std::isprint(_c_value) ? "'" + std::string(1, _c_value) + "'" : "Non displayable";
	else
		printvalue = "impossible";

	std::cout << "char: " << printvalue << std::endl;
}

void Converter::printInt(void) const
{
	std::cout << "int: ";
	if (std::isfinite(_f_value))
	   std::cout <<	_i_value;
	else
		std::cout << "impossible";
	std::cout << std::endl;
}


void Converter::print(void) const
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}
