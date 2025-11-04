/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:19:45 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 20:30:45 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		// --- Orthodox Canonical Form ---
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		// --- Member Function ---

		/* The Factory method.
			It takes the name and target of a form
			and returns a pointer to a newly allocated AForm object.
			The caller is responsible for deleting this object later.
		*/
		AForm* makeForm(const std::string& formName, const std::string& target);

		// --- Custom Exception ---
		/*
			An exception to throw if the form name is not recognized.
		*/
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};


#endif
