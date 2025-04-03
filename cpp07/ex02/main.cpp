/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:58:05 by tao               #+#    #+#             */
/*   Updated: 2025/03/25 23:52:19 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define COLOR "\033[1;36m"
#define RESET "\033[0m"

int main() {
	try {
		std::cout << COLOR << "Test 1 : Construction vide" << RESET << std::endl;
		Array<int> a;
		std::cout << "Taille de a : " << a.size() << std::endl;

		std::cout << "\n" << COLOR << "Test 2 : Construction avec taille" << RESET << std::endl;
		Array<int> b(5);
		for (unsigned int i = 0; i < b.size(); i++) {
			b[i] = i * 10;
		}

		std::cout << "Contenu de b : ";
		for (unsigned int i = 0; i < b.size(); i++) {
			std::cout << b[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "\n" << COLOR << "Test 3 : constructeur par copie" << RESET << std::endl;
		Array<int> c(b);
		std::cout << "Contenu de c (copie de b) : ";
		for (unsigned int i = 0; i < c.size(); i++) {
			std::cout << c[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "\n" << COLOR << "Test 4 : Modif de la copie" << RESET << std::endl;
		c[0] = 999;
		std::cout << "c[0] = " << c[0] << std::endl;
		std::cout << "b[0] = " << b[0] << " (doit être différent)" << std::endl;

		std::cout << "\n" << COLOR << "Test 5 : Affectation (=)" << RESET << std::endl;
		Array<int> d;
		d = c;
		std::cout << "Contenu de d (copie de c) : ";
		for (unsigned int i = 0; i < d.size(); i++) {
			std::cout << d[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "\n" << COLOR << "Test 6 : hors limites" << RESET << std::endl;
		std::cout << d[999] << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}

	return 0;
}
