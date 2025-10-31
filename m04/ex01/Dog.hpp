/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:45:15 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 19:14:38 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

/* C++ inheritance:
	The syntax 'class Dog: public Animal' means that Dog is a derived class of Animal.
	- 'public' inheritance means that public members of Animal remain public in Dog,
		and protected members of Animal remain protected in Dog.
	- Dog inherits the 'type' attribute and the 'getType()' method from Animal
*/
class Dog : public Animal
{
	private:
		// Dog now has a pointer to its own Brain
		Brain* _brain;

	public:
		// --- Orthodox Canonical Form ---
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		~Dog(); // Destructor is automatically virtual because the base's is

		// ----- Member Functions -------
		/* makeSound()
			We 'override' the base class's makeSound() function.
			Because it's virtual in Animal, polymorphism will work correctly.
			When makeSound() is called on an animal pointer pointing to a Dog object,
			this version of the function will be executed.
		*/
		virtual void makeSound() const;

		// helper function to set ideas for testing
		void setIdea(int index, const std::string& idea);

		// helper function to get ideas for testing
		const std::string& getIdea(int index) const;
};


#endif
