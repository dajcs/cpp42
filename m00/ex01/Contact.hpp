/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:13:23 by anemet            #+#    #+#             */
/*   Updated: 2025/10/21 15:37:56 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string> // std::string

class Contact
{
	private:
		// Private data members to store contact info
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		// Public member functions (getters and setters)

		//Setters
		void setFirstName(std::string str);
		void setLastName(std::string str);
		void setNickName(std::string str);
		void setPhoneNumber(std::string str);
		void setDarkestSecret(std::string str);

		// Getters
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
};

#endif
