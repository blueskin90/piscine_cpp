#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const val);
		Fixed(float const val);
		~Fixed(void);

		Fixed & operator=(Fixed const &rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _fixedPointValue;
		static const int _bits_nbr = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
