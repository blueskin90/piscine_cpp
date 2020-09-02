/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 03:40:44 by toliver           #+#    #+#             */
/*   Updated: 2020/07/22 15:29:27 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

std::string	get_param(std::string param_name)
{
	std::string	line;

	std::cout << "Veuillez entrer "<< param_name << " :" << std::endl;
	std::getline(std::cin, line);
	while (line.length() == 0)
	{
		std::cout << "Veuillez entrer une chaine de caracteres non vides pour "<< param_name << " :" << std::endl;
		std::getline(std::cin, line);
	}
	return (line);
}

void	PhoneBook::add(void)
{
	std::string	line;
	if (this->i >= 8)
		std::cout << "Can't ADD more than 8 contacts, stay tuned for MyAwesomePhoneBook V 2.0 !" << std::endl;
	else
	{
		this->contacts[this->i].set_first_name(get_param("le prenom"));
		this->contacts[this->i].set_last_name(get_param("le nom"));
		this->contacts[this->i].set_nickname(get_param("le pseudo"));
		this->contacts[this->i].set_login(get_param("le login"));
		this->contacts[this->i].set_postal_address(get_param("l'addresse postale"));
		this->contacts[this->i].set_email_address(get_param("l'addresse mail"));
		this->contacts[this->i].set_phone_number(get_param("le numero de telephone"));
		this->contacts[this->i].set_birthday_date(get_param("la date de naissance"));
		this->contacts[this->i].set_favourite_meal(get_param("le plat favori"));
		this->contacts[this->i].set_underwear_color(get_param("la couleur de sous-vetements"));
		this->contacts[this->i].set_darkest_secret(get_param("le sombre secret"));
		this->contacts[this->i].set_index(this->i);
		this->i++;
	}
}

void	PhoneBook::search(void) const
{
	std::string	line;
	int			i;

	if (this->i == 0)
	{
		std::cout << "No contact found" << std::endl;
		return ;
	}
	else
	{
		for (i = 0; i < this->i; i++)
			this->contacts[i].print_short();
	}
	std::cout << "Veuillez entrer l'index desire:" << std::endl;
	std::getline(std::cin, line);
	while (line.length() == 0)
	{
		std::cout << "Veuillez entrer une chaine de caracteres non vide:" << std::endl;
		std::getline(std::cin, line);
	}
	i = std::stoi(line);
	if (i < 0 || i >= this->i)
		std::cout << "Invalid index" << std::endl;
	else
		this->contacts[i].print();
}

PhoneBook::PhoneBook(void)
{
	this->i = 0;
}

PhoneBook::~PhoneBook(void)
{
}
