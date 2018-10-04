/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:33:13 by dkliukin          #+#    #+#             */
/*   Updated: 2018/10/01 12:33:15 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_dk.class.hpp"

void add(int *counter, PhoneBook_dk *contact)
{
	if (*counter < USER_LIMIT)
	{
		std::cout << "***************************************" 
		<< std::endl << "        >> NEW USER CREATION <<" << std::endl
		<< "***************************************" << std::endl;
		contact->addNewUser();
		std::cout << "***************************************" 
		<< std::endl << "    >>  USER CREATED SUCCESSFUL  <<" << std::endl
		<< "***************************************" << std::endl;
		*counter += 1;
	}
	else
	{
		std::cout << "Error: Cant add one more user! Please try later!(never again)" << std::endl;
	}
}

void search(int counter, PhoneBook_dk *contact)
{
	std::cout << "|    #Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < counter; i++)
	{
		std::cout << "|" << std::setw(C_WIDTH) << i + 1;
		contact[i].showShortInfo();
	}	
	std::string value;
	std::cout << "Index of user: ";
	std::cin >> value;
	int index = atoi(value.c_str());
	if (index > 0 && index <= counter)
	{
		contact[index-1].showUser();
	}
	else
	{
		std::cout << "Sorry, but there is no user with this index" << std::endl;
	}
}

int main(void)
{
	PhoneBook_dk contact[USER_LIMIT];
	int	counter = 0;
	std::string command;
	while(true)
	{
		std::cout << "Enter command (ADD/SHOW/SEARCH): ";
		std::cin >> command;
		if (!command.compare("EXIT"))
		{
			break ;
		}
		else if (!command.compare("ADD"))
		{
			add(&counter, &contact[counter]);
		}
		else if (!command.compare("SEARCH"))
		{
			search(counter, contact);
		}
		if (std::cin.eof()==1) {
			break;
		}
	}
}