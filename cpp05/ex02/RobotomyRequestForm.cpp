/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:16:17 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 17:28:45 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target), AForm ("Robotomy Form", 25, 5) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copie) :  _target(copie._target), AForm ("Robotomy Form", 25, 5) {
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copie) {
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	return ;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeForExecute() || !this->isSigned())
		throw AForm::GradeTooLowException();

	srand(unsigned(time(NULL)));
	if (rand() % 2) {
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
	}
	return ;
}
