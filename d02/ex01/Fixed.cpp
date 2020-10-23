#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const val)  : _fixedPointValue(val << this->bits_nbr)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(int const val)  : _fixedPointValue(roundf(val * pow(2, this->_bits_nbr))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called"<< std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called"<< std::endl;
	this->_fixedPointValue = raw;
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &nbr)
{
		stream << nbr.getRawBits();
		return stream;
}
