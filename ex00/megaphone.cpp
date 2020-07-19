/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:48:13 by toliver           #+#    #+#             */
/*   Updated: 2020/07/06 18:21:35 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int			main(int ac, char **av)
{
	std::string str = "";

	if (ac < 2)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (ac > 1)
		{
			str.append(av[1]);
			if (ac > 2)
				str.append(" ");
			av++;
			ac--;
		}
	}
	for (size_t i = 0; i < str.size(); i++)
	{		
		str[i] = std::toupper(str[i]);
	}
	std::cout << str << std::endl;
	return(0);
}
