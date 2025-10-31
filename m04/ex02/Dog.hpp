/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:45:15 by anemet            #+#    #+#             */
/*   Updated: 2025/10/31 10:26:45 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

/* AAnimal:
	We just update the Dog to inherit from AAnimal, no other changes needed.
*/

/* C++ inheritance:
	The syntax 'class Dog: public AAnimal' means that Dog is a derived class of AAnimal.
	- 'public' inheritance means that public members of AAnimal remain public in Dog,
		and protected members of AAnimal remain protected in Dog.
	- Dog inherits the 'type' attribute and the 'getType()' method from AAnimal
*/
class Dog : public AAnimal
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
		/* AAnimal  makeSound()
			Dog now inherits from the abstract class AAnimal
			Since Dog provides an implementation for the pure virtual function makeSound()
			it is a "concrete" class, maening we can create instances of it.
			This 'override' fulfills the contract required by AAnimal
		*/
		virtual void makeSound() const;

		// helper function to set ideas for testing
		void setIdea(int index, const std::string& idea);

		// helper function to get ideas for testing
		const std::string& getIdea(int index) const;
};


#endif
