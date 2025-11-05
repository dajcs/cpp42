/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:58:35 by anemet            #+#    #+#             */
/*   Updated: 2025/11/05 17:05:14 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>	// for uintptr_t. This header is from C99 but
						// but it is part of the C++ standard
# include "Data.hpp"	// We need the definition of the Data struct

class Serializer
{
	private:
		// constructors are private, so class is non-instantiable
		Serializer();
		Serializer(const Serializer& src);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:
		// static method belongs to the class, not to a specific object
		// it can be called with ClassName::methodName()
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
