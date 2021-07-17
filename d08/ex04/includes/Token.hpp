#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>

enum type
{
	NUMBER = 1,
	OP,
	PAROPEN,
	PARCLOSE,
};

class Token
{
	public:
		virtual ~Token()
		{
		}
		Token()
		{
		}
		virtual std::string	getPrint() const = 0;
		int			getType() const;
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
	protected:
		int	_type;
};

std::ostream& operator << (std::ostream &output, Token const &arg);

#endif /* TOKEN_HPP */
