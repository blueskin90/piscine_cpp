#include "AInstruction.hpp"

AInstruction::AInstruction() 
{
}

AInstruction::~AInstruction()
{
}

AInstruction::AInstruction(AInstruction const &src)
{
	(void)src;
}

AInstruction &AInstruction::operator =(AInstruction const &rhs)
{
	(void)rhs;
	return (*this);
}
