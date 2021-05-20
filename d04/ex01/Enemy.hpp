#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
class Enemy
{
	private:
		Enemy(void);
	protected:
		int	_hp;
		std::string _type;
	public:
			Enemy(unsigned int hp, std::string const & type);
			Enemy(Enemy const &src);
			virtual ~Enemy();

			std::string virtual getType() const;
			int getHP() const;
			virtual void takeDamage(int);
			Enemy& operator=(Enemy const &rhs);
};

#endif
