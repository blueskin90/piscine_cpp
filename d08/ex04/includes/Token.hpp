#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>

class Token
{
	public:
		~Token()
		{
		}
		Token()
		{
		}
		virtual std::string	getPrint() const = 0;
//		void	exec() = 0;
	private:
		Token(Token const &src)
		{
			(void)src;
		}
		Token &operator=(Token const &rhs)
		{
			(void)rhs;
			return (*this);
		}
};

std::ostream& operator << (std::ostream &output, Token const &arg);

#endif /* TOKEN_HPP */
