/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:40:29 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 16:43:38 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		// Constructor that takes the wapon's type as a string
		Weapon(std::string type);
		~Weapon(void);

		// A "getter" for the type.
		// It returns a const reference to avoid making an unnecessary copy of the string
		// It's const because the function promises not to change the Weapon object
		const std::string& getType(void) const;

		// A "setter" for the type
		// It takes a new string and updates the member variable
		void setType(std::string type);
};

#endif
