/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:41:04 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 21:26:53 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {

	Intern intern;
	Bureaucrat TheCEO("TheCEO", 1);
	Bureaucrat ThePromising("ThePromising", 50);
	Bureaucrat TheNew("TheNew", 150);

	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::string targets[3] = {"Garden", "Bender", "Alice"};

	for (int i = 0; i < 3; i++) {
		AForm *form = intern.makeForm(formTypes[i], targets[i]);
		if (form) {
			TheCEO.signForm(*form);
			TheCEO.executeForm(*form);
			delete form;
		}
	}

	AForm *unknown = intern.makeForm("unknown form", "ErrorTarget");
	if (unknown) delete unknown;

	AForm *shrub = intern.makeForm("shrubbery creation", "Home");
	if (shrub) {
		TheNew.signForm(*shrub);
		TheNew.executeForm(*shrub);
		delete shrub;
	}

	AForm *pardon = intern.makeForm("presidential pardon", "Alice");
	if (pardon) {
		ThePromising.executeForm(*pardon);
		delete pardon;
	}

	return 0;
}
