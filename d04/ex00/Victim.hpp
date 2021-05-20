#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>


class Victim {
	public:

		Victim(std::string const &name);
		Victim(Victim const &src);
		virtual ~Victim(void);

		virtual void	getPolymorphed(void) const;

		std::string const getName(void) const;
	protected:
		Victim& operator=(Victim const &rhs);
		Victim(void);
		std::string const _name;
};

std::ostream& operator<< (std::ostream &output, Victim const &vic);
#endif
