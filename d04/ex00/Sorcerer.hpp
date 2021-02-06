#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>

class Sorcerer {
	public:
		Sorcerer & operator=(Sorcerer const &rhs);

		Sorcerer(std::string const &name, std::string const &title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer(void);

		std::string const getName(void) const;
		std::string const getTitle(void) const;
	private:
		Sorcerer(void);
		std::string const _name;
		std::string const _title;
};

#endif
