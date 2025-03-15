/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:41:04 by tao               #+#    #+#             */
/*   Updated: 2025/03/14 03:24:13 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
	std::cout << "=== TEST CREATION DE FORM ===" << std::endl;
	try {
		Form validForm("ValidForm", 50, 100);
		std::cout << validForm << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}

	try {
		Form formHigh("FormHigh", 0, 50);
	} catch (const Form::GradeTooHighException &e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception générale attrapée : " << e.what() << std::endl;
	}

	try {
		Form formLow("FormLow", 151, 50);
	} catch (const Form::GradeTooLowException &e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception générale attrapée : " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST SIGNATURE DE FORM ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 45);
		Bureaucrat tom("Tom", 120);
		Form taxForm("TaxForm", 50, 100);

		taxForm.beSigned(tom);

		taxForm.beSigned(bob);

		taxForm.beSigned(bob);

	} catch (const Form::GradeTooLowException &e) {
		std::cerr << "Exception attrapée (Form) : " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception générale attrapée : " << e.what() << std::endl;
	}

	return 0;
}
