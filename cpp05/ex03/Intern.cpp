/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:43:58 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 21:26:09 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	return ;
}

Intern::Intern(Intern const &copie) {
	return ;
}

Intern &Intern::operator=(Intern const &copie) {
	return *this;
}

Intern::~Intern() {
	return ;
}

AForm *Intern::createShrubberyForm (std::string formName) {
	return new ShrubberyCreationForm(formName);
}

AForm *Intern::createRobotomyForm (std::string formName) {
	return new RobotomyRequestForm(formName);
}

AForm *Intern::createPresidentialForm (std::string formName) {
	return new PresidentialPardonForm(formName);
}

AForm *Intern::makeForm(std::string formName, std::string targetName) {

	AForm* (*functionForm[3])(std::string) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};

	for (int j = 0; formName[j]; j++)
		formName[j] = std::toupper(formName[j]);

	std::string nameForm[3] = {
		"SHRUBBERY CREATION",
		"ROBOTOMY REQUEST",
		"PRESIDENTIAL PARDON"
	};

	int i = 0;
	while (i < 3) {
		if (nameForm[i] == formName)
			return functionForm[i](targetName);
		i++;
	}

	std::cout << formName << " not found" << std::endl;
	return NULL;

}
