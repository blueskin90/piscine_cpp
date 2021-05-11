/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 23:03:59 by toliver           #+#    #+#             */
/*   Updated: 2021/05/11 18:18:34 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>

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

void	Contact::set_index(const int index)
{
	this->_index = index;
}

void	Contact::print(void) const
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

void	short_display(std::string string)
{
	char arr[11];
	
	std::istringstream is(string);
	if (string.size() <= 10)
	{
		is >> std::setw(10) >> arr;
		std::cout << std::setw(10) << arr;
	}
	else
	{
		is >> std::setw(10) >> arr;
		std::cout << arr << ".";
	}
}

void	Contact::print_short(void) const
{
	std::cout << std::setw(10) << this->_index << "|";
	short_display(this->_first_name);
	std::cout << "|";
	short_display(this->_last_name);
	std::cout << "|";
	short_display(this->_nickname);
	std::cout << std::endl;
}



Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}
