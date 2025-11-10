/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:23:02 by anemet            #+#    #+#             */
/*   Updated: 2025/11/10 16:53:28 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

/*
	Implementation of the begin() method

	`template <typename T, typename Container>` : Specifies the template function
	`typename MutantStack<T, Container>::iterator`: The return type. We use `typename`
		because the compiler doesn't know what`iterator` is until `T` is specified.
	`MutantStack<T, Container>::begin()` : The function name, scoped to the class

	`this->c` refers to the protected member 'c' of the base std::stack class,
		which is the underlying container. We simply call its `begin()` method.
*/

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

// Const version of begin()
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}


/*
	Implementation of the end() method
	It returns an iterator pointing to the position *after* the last element
*/
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

// Const version of end()
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return this->c.end();
}


/*
	Implementatioin of the rbegin() method for reverse iterators
	It returns a reverse iterator pointing to the last element (which is the beginning
		for reverse iteration)
*/
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return this->c.rbegin();
}

// Const version of rbegin()
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return this->rbegin()
}


/*
	Implementation of the rend() method for reverse iterators
	It returns a reverse iterator pointing to the position *before* the first element
*/
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return this->c.rend();
}

// Const version of rend()
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return this->c.rend();
}

#endif // MUTANTSTACK_TPP
