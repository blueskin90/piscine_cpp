#include "AInstruction.hpp"

class IncPtr: public AInstruction
{
	void execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it);
};

class DecPtr: public AInstruction
{
	void execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it);
};

class IncPtrValue: public AInstruction
{
	void execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it);
};

class DecPtrValue: public AInstruction
{
	void execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it);
};

class Print: public AInstruction
{
	void execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it);
};

class Read: public AInstruction
{
	void execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it);
};

class StartLoop: public AInstruction
{
	void execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it);
};

class EndLoop: public AInstruction
{
	void execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it);
};
