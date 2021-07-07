#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <iostream>
#include <vector>

class AInstruction
{
	class NullValueException: public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return ("was given a null value for buffer or pointer to size_t.");
			}
	};
	public:
		~AInstruction();
		virtual void execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *ite) = 0;
		AInstruction();
	private:
		AInstruction& operator=(AInstruction const &rhs);
		AInstruction(AInstruction const &src);
};

#endif /* INSTRUCTION_HPP */
