/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:40:34 by anemet            #+#    #+#             */
/*   Updated: 2025/10/21 15:47:07 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"  //PhoneBook uses the Contact class

class PhoneBook
{
	private:
		// Static array of 8 contacts
		Contact contacts[8];
		// index to track where to add the next contact
		int	addIndex;
		// total number of contacts added
		int contactCount;

	public:
		// Constructor: a special function that is called when an object is created
		// We're using it to initialize our private variables
		PhoneBook(void);

		// Public methods to interact with the phonebook
		void addContact(void);
		void searchContacts(void);
};

#endif
