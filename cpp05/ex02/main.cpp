/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:41:04 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 17:32:40 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat bob("Bob", 1);
	Bureaucrat tom("Tom", 50);
	Bureaucrat jerry("Jerry", 150);

	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Alice");

	std::cout << "\n=== TEST SHRUBBERY CREATION FORM ===" << std::endl;
	bob.signForm(shrub);
	bob.executeForm(shrub);

	std::cout << "\n=== TEST ROBOTOMY REQUEST FORM ===" << std::endl;
	bob.signForm(robot);
	bob.executeForm(robot);

	std::cout << "\n=== TEST PRESIDENTIAL PARDON FORM ===" << std::endl;
	bob.signForm(pardon);
	bob.executeForm(pardon);

	std::cout << "\n=== TEST ÉCHEC AVEC JERRY ===" << std::endl;
	jerry.signForm(shrub);
	jerry.executeForm(shrub);

	std::cout << "\n=== TEST ÉCHEC SANS SIGNATURE ===" << std::endl;
	tom.executeForm(pardon);

	return 0;
}
