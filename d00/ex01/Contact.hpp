/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 23:03:58 by toliver           #+#    #+#             */
/*   Updated: 2020/07/22 14:16:25 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <locale>

class Contact {
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string	_login;
		std::string	_postal_address;
		std::string	_email_address;
		std::string _phone_number;
		std::string _birthday_date;
		std::string	_favourite_meal;
		std::string	_underwear_color;
		std::string	_darkest_secret;
		int			_index;

	public:
		Contact(void);
		~Contact(void);
		void		set_first_name(const std::string str);
		void		set_last_name(const std::string str);
		void		set_nickname(const std::string str);
		void		set_login(const std::string str);
		void		set_postal_address(const std::string str);
		void		set_email_address(const std::string str);
		void		set_phone_number(const std::string str);
		void		set_birthday_date(const std::string str);
		void		set_favourite_meal(const std::string str);
		void		set_underwear_color(const std::string str);
		void		set_darkest_secret(const std::string str);
		void		set_index(const int index);
		void		print_short(void) const;
		void		print(void) const;
};

#endif
