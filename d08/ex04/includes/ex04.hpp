#ifndef EX04_HPP
#define EX04_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include "Token.hpp"
#include "NumToken.hpp"
#include "OpToken.hpp"
#include "ParOpenToken.hpp"
#include "ParCloseToken.hpp"

bool	isNumber(char c);
bool	isSign(char c);
bool	isPar(char c);
void	vectorToStack(std::vector<Token*> *tokens, std::stack<Token*> *result);

bool	tokenizeString(const char* str, std::vector<Token*> *list);

void	dumpTokens(std::vector<Token*> tokens);
void	dumpStack(std::stack<Token*>result);
void	dumpNumStack(std::stack<Token*>result);
void	dumpOpType(OpToken* tok);

bool	postfixConversion(std::vector<Token*> *tokens);

#endif /* EX04_HPP */
