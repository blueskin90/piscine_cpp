#include "Human.hpp"

Human::Human(void)
{
}

Human::~Human(void)
{
}

Brain const &Human::getBrain(void) const
{
	Brain const	&ref = this->_brain;
	return (ref);
}

std::string Human::identify(void) const
{
	return (this->getBrain().identify());
}
