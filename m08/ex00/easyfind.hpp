/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:47:59 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 20:07:26 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm> // std::find
#include <iostream>  // std::cout
#include <exception> // std::exception

/* NotFoundException
	A custom exception class to be thrown when an element is not found
	Inheriting form the base std::exception class
*/
class NotFoundException : public std::exception
{
	public:
		/* what()
			The what() method is a virtual function is std::exception
			We override it to return a custom error message.
			'const throw()' is an exception specification that guarantees
			this function will not throw any exceptions itself
		*/
		virtual const char* what() const throw()
		{
			return "Element not found in container";
		}
};


/* easyfind() function template
	'template': keyword, -> this is a generic function
	T: the type of the container (e.g., std::vector<int>)
	Input:
		T & container: A reference to the container we want to search in
		int value: The integer we are looking for
	Return:
		T::iterator - an iterator which points to the first found element.
						we need the 'typename' keyword to tell to the compiler
						that T::iterator is a type, not a static member
*/
template <typename T>
typename T::iterator easyfind(T & container, int value);

// including template implementation in the easyfind.tpp
#include "easyfind.tpp"


#endif
