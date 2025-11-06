/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:07:46 by anemet            #+#    #+#             */
/*   Updated: 2025/11/06 20:23:45 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



template <typename T>
typename T::iterator easyfind(T & container, int value)
{
	/*
		Here we use std::find from the <algorithm> library.

		std::find takes 3 arguments:
		1. an iterator to the beginning of the range to search (container.begin())
		2. an iterator to the end of the range to search (container.end())
		3. the value to look for

		It returns an iterator.
	*/
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	/*
		when std::find fails to find the value, it returns the 'end' iterator
		(the second arguemt we passed to it)
	*/
	if (it == container.end())
	{
		// throw exception if value not found
		throw NotFoundException();
	}
	// if value has been found, return 'it'
	return it;
}
