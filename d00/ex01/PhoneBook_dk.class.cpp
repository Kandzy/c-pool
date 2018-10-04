/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_dk.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:39:11 by dkliukin          #+#    #+#             */
/*   Updated: 2018/10/01 12:39:12 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_dk.class.hpp"

PhoneBook_dk::PhoneBook_dk(){ return ; }
PhoneBook_dk::~PhoneBook_dk(){ return ; }

void PhoneBook_dk::showShortInfo()
{
	std::string firstName = this->_firstName;
	std::string lastName = this->_lastName;
	std::string nickname = this->_nickname;
	if (firstName.length() > 10)
	{
		firstName = firstName.substr(0,9);
		firstName += ".";
	}
	if (lastName.length() > 10)
	{
		lastName = lastName.substr(0,9);
		lastName += ".";
	}
	if (nickname.length() > 10)
	{
		nickname = nickname.substr(0,9);
		nickname += ".";
	}
	std::cout << "|" << std::setw(C_WIDTH) << firstName;
	std::cout << "|" << std::setw(C_WIDTH) << lastName;
	std::cout << "|" << std::setw(C_WIDTH) << nickname << "|" << std::endl;
}

void PhoneBook_dk::showUser()
{
	std::cout << "Name: " + this->_firstName << std::endl <<
	"last: " + this->_lastName << std::endl <<
	"nick: " + this->_nickname << std::endl <<
	"login: " + this->_login << std::endl <<
	"postalAddress: " + this->_postalAddress << std::endl <<
	"email: " + this->_email << std::endl <<
	"phone: " + this->_phone << std::endl <<
	"BD: " + this->_birdthDate << std::endl <<
	"FM: " + this->_favoriteMeal << std::endl <<
	"UNC: " + this->_underwearColor << std::endl <<
	"DS: " + this->_darkestSecret << std::endl;
	return ;
}

void PhoneBook_dk::addNewUser()
{
	std::string	value;
	std::cout << "Enter first name: ";
	std::cin >> value;
	this->setFirstName(value);
	std::cout << "Enter last name: ";
	std::cin >> value;
	this->setLastName(value);
	std::cout << "Enter nickname: ";
	std::cin >> value;
	this->setNickname(value);
	std::cout << "Enter Login: ";
	std::cin >> value;
	this->setLogin(value);
	std::cout << "Enter postal address: ";
	std::cin >> value;
	this->setPostalAddress(value);
	std::cout << "Enter email: ";
	std::cin >> value;
	this->setEmail(value);
	std::cout << "Enter phone number: ";
	std::cin >> value;
	this->setPhone(value);
	std::cout << "Enter birdthdate: ";
	std::cin >> value;
	this->setBirdthD(value);
	std::cout << "Enter favorite meal: ";
	std::cin >> value;
	this->setFavoriteMeal(value);
	std::cout << "Enter underwear color: ";
	std::cin >> value;
	this->setUnderwearColor(value);
	std::cout << "Enter darkest secret: ";
	std::cin >> value;
	this->setSecret(value);
	return ;
}

void PhoneBook_dk::setFirstName(std::string value)
{
	this->_firstName = value;
}

void PhoneBook_dk::setLastName(std::string value)
{
	this->_lastName = value;
}

void PhoneBook_dk::setNickname(std::string value)
{
	this->_nickname = value;
}

void PhoneBook_dk::setLogin(std::string value)
{
	this->_login = value;
}

void PhoneBook_dk::setPostalAddress(std::string value)
{
	this->_postalAddress = value;
}

void PhoneBook_dk::setEmail(std::string value)
{
	this->_email = value;
}

void PhoneBook_dk::setPhone(std::string value)
{
	this->_phone = value;
}

void PhoneBook_dk::setBirdthD(std::string value)
{
	this->_birdthDate = value;
}

void PhoneBook_dk::setFavoriteMeal(std::string value)
{
	this->_favoriteMeal = value;
}

void PhoneBook_dk::setUnderwearColor(std::string value)
{
	this->_underwearColor = value;
}

void PhoneBook_dk::setSecret(std::string value)
{
	this->_darkestSecret = value;
}
