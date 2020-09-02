#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int		i;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void) const;
};

#endif
