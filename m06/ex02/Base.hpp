/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:18:14 by anemet            #+#    #+#             */
/*   Updated: 2025/11/05 20:22:22 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

/* Base class with a virtual destructor
	When we delete a derived class object through a Base pointer,
	the virtual destructor ensures that the destructor of the "actual"
	derived class (A, B or C) is called first, followed by the Base class destructor.
*/
class Base
{
	public:
		// Virtual destructor
		virtual ~Base();
};

#endif
