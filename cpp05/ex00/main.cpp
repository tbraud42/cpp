/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:41:04 by tao               #+#    #+#             */
/*   Updated: 2025/03/13 21:27:25 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat TheCEO("TheCEO", 1);
		Bureaucrat ThePromising("ThePromising", 42);
		Bureaucrat TheNew("TheNew", 150);

		std::cout << TheCEO << std::endl;
		std::cout << ThePromising << std::endl;
		std::cout << TheNew << std::endl;

		std::cout << "\n=== Test des augmentations de grade ===" << std::endl;
		ThePromising.upGrade();
		std::cout << ThePromising << std::endl;
		TheCEO.upGrade();

	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	try {
		std::cout << "\n=== Test des diminutions de grade ===" << std::endl;
		Bureaucrat TheSlaker("TheSlaker", 149);
		TheSlaker.downGrade();
		std::cout << TheSlaker << std::endl;
		TheSlaker.downGrade();

	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	try {
		std::cout << "\n=== Test d'une création avec un grade trop élevé ===" << std::endl;
		Bureaucrat high("High", 0);

	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	try {
		std::cout << "\n=== Test d'une création avec un grade trop bas ===" << std::endl;
		Bureaucrat low("Low", 151);

	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	return 0;
}
