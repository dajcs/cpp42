/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:57:03 by anemet            #+#    #+#             */
/*   Updated: 2025/11/05 11:07:24 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string> // for std::string

/* Scalarconverter
	- it is designed as a static class. This means we will never create an
		instance of it like 'ScalarConverter myConverter;'
	- we will call its functions directly using the class name, like
		'ScalarConverter::convert()'
	- to enforce non-instantiable, we make the constructor private
	- this is the C++ way to create a utility class that just groups
		related functions
*/
class ScalarConverter
{
	public:
		// The only public method, the entry point for the conversion process
		// It's static, so we can call it without creating an object
		// Takes a constant reference to a string to avoid making unnecessary copies
		static void convert(const std::string& literal);
	private:
		// --- Orthodox Canonical Form (made private) ---
		// By declaring these in the private section and NOT providing an implementation
		// we prevent anyone from creating, copying, or assigning ScalarConverter objects.
		// This enforces the "static class" design.
		ScalarConverter(); // Default Constructor
		ScalarConverter(const ScalarConverter& other); //Copy constructor
		ScalarConverter& operator=(const ScalarConverter& other); // Private Copy Assignment Operator
		~ScalarConverter(); // Private Destructor
};


#endif
