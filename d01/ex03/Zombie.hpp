#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string	_name;
		std::string	_type;
	public:
		Zombie(void);
		Zombie(std::string const &name, std::string const &type);
		~Zombie(void);
		void announce(void) const;
};

#endif
