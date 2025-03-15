/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:16:11 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 17:14:04 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target), AForm ("Presidential Form", 25, 5) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copie) : _target(copie._target), AForm ("Presidential Form", 25, 5) {
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copie) {
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	return ;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeForExecute() || !this->isSigned())
		throw AForm::GradeTooLowException();
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}
