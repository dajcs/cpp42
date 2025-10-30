/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:17:43 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 09:15:59 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		// this attribute will be inherited by all derived classes
		std::string type;

	public:
		// --- Orthodox Canonical Form ---
		// 1. Default Constructor: Called when an object is created without any arguments
		Animal();
		// 2. Copy Constructor: Called when a new object is created as a copy of an existing object
		Animal(const Animal &other);
		// 3. Copy Assignment Operator: Called when an existing object is assigned the value of another object
		Animal& operator=(const Animal &other);
		/* 4. Destructor: Called when an object is destroyed
			- It is virtual to ensure that when we delete an object through a base class pointer,
				the correct destructor of the derived class is called first.
		*/
		virtual ~Animal();

		// ----------- Member Functions ---------------
		/* makeSound()
			- is a 'virtual' function. This is the key to polymorphism.
				it means that when called on a base class pointer, the version of the function
				corresponding to the object's actual type (e.g., Dog or Cat) will be executed.
			- the 'const' at the end means this function does not modify the object's state
		*/
		virtual void makeSound() const;

		// A simple getter function to access the protected 'type' attribute
		const std::string &getType() const;
};


#endif
