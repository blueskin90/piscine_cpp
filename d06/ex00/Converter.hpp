#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <cmath>
#include <iomanip>

class Converter {
	public:
		Converter(std::string param);
		~Converter(void);
		std::string getString(void) const;
		void print(void) const;
	private:
		Converter(Converter const &src);
		Converter& operator=(Converter const &rhs);
		Converter(void);

		void printFloat(void) const;
		void printDouble(void) const;
		void printChar(void) const;
		void printInt(void) const;

		void	convert(void);

		std::string _string;
		float _f_value;
		double _d_value;
		int _i_value;
		char _c_value;
};

std::ostream& operator<< (std::ostream &output, Converter const &converter);

#endif /* CONVERTER_HPP */
