/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:38:09 by anemet            #+#    #+#             */
/*   Updated: 2025/10/25 15:42:00 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

// Harl is a class designed to simulate a character who complains at different levels
class Harl
{
	private:
		/*
			These are the specific complaint functions. They are private because
			they should only be called through the public `complain` interface.
		*/
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl(void);
		~Harl(void);

		// the public interface to make Harl complain
		void complain(std::string level);
};

#endif
