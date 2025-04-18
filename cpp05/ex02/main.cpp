/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:41:04 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 21:27:59 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	Bureaucrat TheCEO("TheCEO", 1);
	Bureaucrat ThePromising("ThePromising", 50);
	Bureaucrat TheNew("TheNew", 150);

	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Alice");

	std::cout << "\n=== TEST SHRUBBERY CREATION FORM ===" << std::endl;
	TheCEO.signForm(shrub);
	TheCEO.executeForm(shrub);

	std::cout << "\n=== TEST ROBOTOMY REQUEST FORM ===" << std::endl;
	TheCEO.signForm(robot);
	TheCEO.executeForm(robot);

	std::cout << "\n=== TEST PRESIDENTIAL PARDON FORM ===" << std::endl;
	TheCEO.signForm(pardon);
	TheCEO.executeForm(pardon);

	std::cout << "\n=== TEST ÉCHEC AVEC TheNew ===" << std::endl;
	TheNew.signForm(shrub);
	TheNew.executeForm(shrub);

	std::cout << "\n=== TEST ÉCHEC SANS SIGNATURE ===" << std::endl;
	ThePromising.executeForm(pardon);

	return 0;
}
