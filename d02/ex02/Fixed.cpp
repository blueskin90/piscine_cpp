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

Fixed::Fixed(int const val)  : _fixedPointValue(val << Fixed::_bits_nbr)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const val)  : _fixedPointValue(roundf(val * (1 << Fixed::_bits_nbr)))
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

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> Fixed::_bits_nbr);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << Fixed::_bits_nbr));
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &nbr)
{
		stream << nbr.toFloat();
		return stream;
}
bool Fixed::operator>(Fixed const& rhs) const {
    return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<(Fixed const& rhs) const {
    return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=(Fixed const& rhs) const {
    return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=(Fixed const& rhs) const {
    return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==(Fixed const& rhs) const {
    return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(Fixed const& rhs) const {
    return (this->toFloat() != rhs.toFloat());
}

Fixed Fixed::Fixed::operator+(Fixed const& rhs) const {
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::Fixed::operator-(Fixed const& rhs) const {
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::Fixed::operator*(Fixed const& rhs) const {
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::Fixed::operator/(Fixed const& rhs) const {
	if (rhs.toFloat() == 0) {
		std::cout << "Dividing by zero is forbidden";
		return (Fixed(0));
	}
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::Fixed::operator++() {
    ++(this->_fpvalue);
    return (*this);
}

Fixed &Fixed::Fixed::operator--() {
    --(this->_fpvalue);
    return (*this);
}

Fixed Fixed::Fixed::operator++(int) {
    Fixed tmp = *this;

    ++(*this);
    return (tmp);
}

Fixed Fixed::Fixed::operator--(int) {
    Fixed tmp = *this;

    --(*this);
    return (tmp);
}

Fixed &Fixed::min(Fixed &nb1, Fixed &nb2) {
    if (nb1.toFloat() < nb2.toFloat())
        return (nb1);
    return (nb2);
}

Fixed &Fixed::max(Fixed &nb1, Fixed &nb2) {
    if (nb1.toFloat() > nb2.toFloat())
        return (nb1);
    return (nb2);
}

const Fixed &Fixed::min(Fixed const &nb1, Fixed const &nb2) {
    if (nb1.toFloat() < nb2.toFloat())
        return (nb1);
    return (nb2);
}

const Fixed &Fixed::max(Fixed const &nb1, Fixed const &nb2) {
    if (nb1.toFloat() > nb2.toFloat())
        return (nb1);
    return (nb2);
}
