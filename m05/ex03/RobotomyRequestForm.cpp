/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:39:02 by anemet            #+#    #+#             */
/*   Updated: 2025/11/04 14:46:15 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
						AForm("Robotomy Request Form", "Default Target", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
						AForm("Robotomy Request Form", target, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::performAction() const
{
	std::cout << "* VRRRRR... BZZZZZ... DRILLING NOISES... *" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy on " << this->getTarget() << " has failed." << std::endl;
}
