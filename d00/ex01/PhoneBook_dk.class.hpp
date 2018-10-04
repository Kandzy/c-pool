/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_dk.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:39:05 by dkliukin          #+#    #+#             */
/*   Updated: 2018/10/01 12:39:08 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PB_CLASS_HPP
#define PB_CLASS_HPP

#define USER_LIMIT 8
#define C_WIDTH 10

#include <iostream>
#include <iomanip>

class PhoneBook_dk{
	//Fields
	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickname;
		std::string		_login;
		std::string		_postalAddress;
		std::string		_email;
		std::string		_phone;
		std::string		_birdthDate;
		std::string		_favoriteMeal;
		std::string		_underwearColor;
		std::string		_darkestSecret;
	//Methods
	public:
		//Constructor
		PhoneBook_dk(void);

		//Destructor
		~PhoneBook_dk(void);

		//First Name
		void setFirstName(std::string value);
		
		//Last Name
		void setLastName(std::string value);
		
		//Nickname
		void setNickname(std::string value);
		
		//Login
		void setLogin(std::string value);
		
		//Postal Address
		void setPostalAddress(std::string value);
		
		//Email Address
		void setEmail(std::string value);
		
		//Phone number
		void setPhone(std::string value);
		
		//Birdth Date
		void setBirdthD(std::string value);

		//Favorite Meal
		void setFavoriteMeal(std::string value);

		//Underwear
		void setUnderwearColor(std::string value);
		
		//Secrets
		void setSecret(std::string value);

		void addNewUser();
		void showUser();
		void showShortInfo();

};

#endif
