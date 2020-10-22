#include "Brain.hpp"

Brain::Brain(size_t neurons) : _neurons(neurons)
{
}

Brain::Brain(void) : _neurons(1)
{
}

Brain::~Brain(void)
{
}

std::string Brain::identify(void) const
{
	std::ostringstream	oss;

	oss << "0x" << std::hex << std::uppercase << (unsigned long long int) this;
	return (oss.str());
}

size_t	Brain::get_neurons(void) const
{
	return (this->_neurons);
}

void	Brain::set_neurons(size_t neurons)
{
	this->_neurons = neurons;
}
