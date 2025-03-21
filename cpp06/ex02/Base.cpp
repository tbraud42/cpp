/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 01:08:22 by tao               #+#    #+#             */
/*   Updated: 2025/03/20 00:03:14 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void) {

	srand(unsigned(time(NULL)));
	int random = rand() % 3;
	if (random == 0) {
		return new A();
	} else if (random == 1) {
		return new B();
	} else {
		return new C();
	}
}

void identify(Base* p) {

	if (A *classA = dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (B *classB = dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (C *classC = dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "type not found" << std::endl;
	}

}

void identify(Base& p) {

	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast &) {}

	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast &) {}

	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast &) {}

	std::cout << "type not found" << std::endl;

}

std::ostream &operator<<(std::ostream &out, const Base &Base) {
	return out;
}
