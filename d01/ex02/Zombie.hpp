#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string	name;
		std::string	type;
	public:
		Zombie(void);
		~Zombie(void);
		void advert(void) const;
};

#endif
