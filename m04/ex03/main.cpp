/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:30:57 by anemet            #+#    #+#             */
/*   Updated: 2025/11/02 14:37:36 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/*


  < ICharacter >                                < IMateriaSource >
        ^                                               ^
        | (implements)                                  | (implements)
        |                                               |
 [ Character ]                                   [ MateriaSource ]
        |                                               |
        |                                               |
        ' - - -has an inventory of [AMateria*] - - -  - '
                                |                       |
                                |                       ' - - learns/creates - > { AMateria }
                                |                                                (Abstract)
                                '  - - - - - - - - - - - - - - - - - - - - - > ^
                                                                               | (inherits)
                                                                    +----------+----------+
                                                                    |                     |
                                                               [  Ice  ]             [  Cure  ]

*/

void runSubjectTests()
{
	std::cout << "--- SUBJECT TESTS ---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << "--- END OF SUBJECT TESTS ---\n" << std::endl;
}

void rundDeepCopyTests()
{
	std::cout << "--- DEEP COPY TESTS ---" << std::endl;
	Character* cloud = new Character("Cloud");
	cloud->equip(new Ice());
	cloud->equip(new Cure());

	// Test copy constructor
	Character* tifa = new Character(*cloud);
	std::cout << "Original is " << cloud->getName() << ", copy is " << tifa->getName() << std::endl;

	// Test assignment operator
	Character* barret = new Character("Barret");
	*barret = *cloud;
	std::cout << "Original is " << cloud->getName() << ", assigned is " << barret->getName() << std::endl;

	std::cout << "\nCloud uses his materia on Tifa:" << std::endl;
	cloud->use(0, *tifa); // Cloud uses Ice on Tifa
	cloud->use(1, *tifa); // Cloud uses Cure on Tifa

	std::cout << "\nBarret (copy of Cloud) uses his materia on Tifa:" <<std::endl;
	barret->use(0, *tifa); // Barret should alse have Ice
	barret->use(1, *tifa); // Barret should also have Cure

	delete cloud; // Deleting Cloud should not affect Tifa or Barret's materias
	std::cout << "\nCloud has been deleted." << std::endl;

	std::cout << "\nTifa (copy of Cloud) uses her materia on Barret:" << std::endl;
	tifa->use(0, *barret);
	tifa->use(1, *barret);

	delete tifa;
	delete barret;
	std::cout << "-- END OF DEEP COPY TESTS ---\n" << std::endl;
}

void runInventoryTests()
{
	std::cout << "--- INVENTORY AND UNEQUIP TESTS ---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* hero = new Character("Hero");

	// Equip 4 items
	AMateria* m0 = src->createMateria("ice");
	AMateria* m1 = src->createMateria("cure");
	AMateria* m2 = src->createMateria("ice");
	AMateria* m3 = src->createMateria("cure");

	hero->equip(m0);
	hero->equip(m1);
	hero->equip(m2);
	hero->equip(m3);

	// Try to equip a 5th, should do nothing
	AMateria* extra = src->createMateria("ice");
	hero->equip(extra);
	std::cout << "Tried to equip a 5th Materia. It should have been ignored." << std::endl;

	// 'extra' was not equipped, so we own it and must delete it
	delete extra;

	// Unequip item at index 1
	// The hero no longer owns m1, but we still have the pointer, so we can manage it.
	hero->unequip(1);
	std::cout << "Unequipped the Cure Materia from slot 1." << std::endl;
	// We are now responsible for m1. Let's delete it to prevent a leak.
	delete m1;
	std::cout << "Manually deleted the unequipped Materia (m1)." << std::endl;

	// Equip a new materia in the now-empty slot.
	AMateria* new_m1 = src->createMateria("ice");
	hero->equip(new_m1);
	hero->use(1, *hero);  // Should now be ice

	// Deleting the hero will delete materias at slots 0, 1(new), 2, and 3
	delete hero;
	delete src;
	std::cout << "--- END OF INVENTORY TESTS --- \n" << std::endl;
}


int main()
{
	runSubjectTests();
	rundDeepCopyTests();
	runInventoryTests();

	return 0;
}
