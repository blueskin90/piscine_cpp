#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const val);
		Fixed(float const val);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
		Fixed & operator=(Fixed const &rhs);
		bool operator>(Fixed const &rhs) const;
		bool operator<(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;
		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs) const;
		Fixed operator/(Fixed const &rhs) const;
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static const Fixed &min(Fixed const &nb1, Fixed const &nb2);
		static const Fixed &max(Fixed const &nb1, Fixed const &nb2);
		static Fixed &min(Fixed &nb1, Fixed &nb2);
		static Fixed &max(Fixed &nb1, Fixed &nb2);
	private:
		int _fixedPointValue;
		static const int _bits_nbr = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
