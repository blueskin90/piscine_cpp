#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iomanip>
#include <sstream>

class Brain {
	private:
		size_t	_neurons;
	public:
		Brain(size_t neurons);
		Brain(void);
		~Brain(void);
		std::string	identify(void) const;
		size_t	get_neurons(void) const;
		void	set_neurons(size_t neurons);
};

#endif
