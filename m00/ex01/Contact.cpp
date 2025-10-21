/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:21:54 by anemet            #+#    #+#             */
/*   Updated: 2025/10/21 15:40:12 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Setters
void Contact::setFirstName(std::string str)
{
	this->firstName = str;
}

void Contact::setLastName(std::string str)
{
	this->lastName = str;
}

void Contact::setNickName(std::string str)
{
	this->nickName = str;
}

void Contact::setPhoneNumber(std::string str)
{
	this->phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
	this->darkestSecret = str;
}

// Getters
std::string Contact::getFirstName(void)
{
	return (this->firstName);
}

std::string Contact::getLastName(void)
{
	return (this->lastName);
}

std::string Contact::getNickName(void)
{
	return (this->nickName);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}
