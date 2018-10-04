/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:50:33 by dkliukin          #+#    #+#             */
/*   Updated: 2018/10/01 10:50:37 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void screaming_voice(int num, char *args[])
{
	for (int i = 1; i < num; i++)
	{
		size_t len = strlen(args[i]);
		for (size_t j = 0; j < len; j++)
		{
			std::cout << (char)toupper(args[i][j]);
		}
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		screaming_voice(argc, argv);
	}
	else
	{
	   std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}
