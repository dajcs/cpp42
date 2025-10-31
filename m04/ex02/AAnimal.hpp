/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:17:43 by anemet            #+#    #+#             */
/*   Updated: 2025/10/31 10:13:22 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

// --- AAnimal is now an abstract class -----
class AAnimal
{
	protected:
		// this attribute will be inherited by all derived classes
		std::string type;

	public:
		/* AAnimal:
			Constructors and destructors still exist and are needed.
			The constructor will be called by derived classes (Dog, Cat)
		*/
		// --- Orthodox Canonical Form ---
		// 1. Default Constructor: Called when an object is created without any arguments
		AAnimal();
		// 2. Copy Constructor: Called when a new object is created as a copy of an existing object
		AAnimal(const AAnimal &other);
		// 3. Copy Assignment Operator: Called when an existing object is assigned the value of another object
		AAnimal& operator=(const AAnimal &other);
		/* 4. Destructor: Called when an object is destroyed
			- It is virtual to ensure that when we delete an object through a base class pointer,
				the correct destructor of the derived class is called first.
		*/
		// AAnimal: The 'virtual` destructor is still essential for polymorphism
		virtual ~AAnimal();

		// ----------- Member Functions ---------------
		/* makeSound()
			- is a 'virtual' function. This is the key to polymorphism.
				it means that when called on a base class pointer, the version of the function
				corresponding to the object's actual type (e.g., Dog or Cat) will be executed.
			- the 'const' at the end means this function does not modify the object's state
		*/
		/* AAnimal - Pure Virtual Function:
			The '=0' at the end makes makeSound() a "pure virtual function".
			1. It makes the entire AAnimal class ABSTRACT.
				It is not possible anymore to create instance like `AAnimal myAnimal;` or
				`new AAnimal();`
			2. It forces any derived class (like Dog or Cat) to provide its own implementation
				of `makeSound()`. If a derived class fails to do so, it also becomes an
				abstract class.
		*/
		virtual void makeSound() const = 0;

		// A simple getter function to access the protected 'type' attribute
		const std::string &getType() const;
};


#endif
