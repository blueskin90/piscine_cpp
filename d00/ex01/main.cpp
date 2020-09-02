/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:48:13 by toliver           #+#    #+#             */
/*   Updated: 2020/07/22 15:31:15 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "phonebook.h"

int			main(void)
{
	std::string	line;
	PhoneBook	phonebook;
	
	std::cout << "Bienvenue dans mon AwEsOmE livre de contacts !" << std::endl;
	while (1)
	{
		std::cout << "Veuillez entrer votre commande:" << std::endl;
		std::getline(std::cin, line);
		if (line.compare("EXIT") == 0)
			break;
		else if (line.compare("ADD") == 0)
			phonebook.add();
		else if (line.compare("SEARCH") == 0)
			phonebook.search();
	}
	return(0);
}
