/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/04/02 16:46:36 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

int main () {
	try {
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span  : " << sp.longestSpan() << std::endl;

		try {
			sp.addNumber(42);
		} catch (const std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}

		Span rangeSpan(10);
		rangeSpan.addRange(10, 15);

		std::cout << "Shortest span (plage 10-15) : " << rangeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span  (plage 10-15) : " << rangeSpan.longestSpan() << std::endl;

		Span copy = sp;
		std::cout << "Copie - Shortest span : " << copy.shortestSpan() << std::endl;
		std::cout << "Copie - Longest span  : " << copy.longestSpan() << std::endl;

		Span smallContainers;
		smallContainers.addNumber(42);
		try {
			smallContainers.shortestSpan();
		} catch (const std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}

		try {
			smallContainers.longestSpan();
		} catch (const std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}

	} catch (const std::exception& e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}

	return 0;
}
