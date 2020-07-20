/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 23:03:59 by toliver           #+#    #+#             */
/*   Updated: 2020/07/20 04:07:53 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->_last_name);
}
std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

void	Contact::set_first_name(const std::string str)
{
	this->_first_name = str;
}

void	Contact::set_last_name(const std::string str)
{
	this->_last_name = str;
}
void	Contact::set_nickname(const std::string str)
{
	this->_nickname = str;
}

void	Contact::set_login(const std::string str)
{
	this->_login = str;
}
void	Contact::set_postal_address(const std::string str)
{
	this->_postal_address = str;
}

void	Contact::set_email_address(const std::string str)
{
	this->_email_address = str;
}

void	Contact::set_phone_number(const std::string str)
{
	this->_phone_number = str;
}

void	Contact::set_birthday_date(const std::string str)
{
	this->_birthday_date = str;
}

void	Contact::set_favourite_meal(const std::string str)
{
	this->_favourite_meal = str;
}

void	Contact::set_underwear_color(const std::string str)
{
	this->_underwear_color = str;
}

void	Contact::set_darkest_secret(const std::string str)
{
	this->_darkest_secret = str;
}

void	Contact::print(void)
{
	std::cout << this->_first_name << std::endl <<
		this->_last_name << std::endl <<
		this->_nickname << std::endl <<
		this->_login << std::endl <<
		this->_postal_address << std::endl <<
		this->_email_address << std::endl <<
		this->_phone_number << std::endl <<
		this->_birthday_date << std::endl <<
		this->_favourite_meal << std::endl <<
		this->_underwear_color << std::endl <<
		this->_darkest_secret << std::endl;
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}
