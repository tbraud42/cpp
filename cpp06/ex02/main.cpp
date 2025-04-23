/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:58:05 by tao               #+#    #+#             */
/*   Updated: 2025/03/21 05:41:59 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>

int main(int ac, char **av) {

	Base *ptr = generate();

	std::cout << "Identify using pointer: ";
	identify(ptr);

	std::cout << "Identify using reference: ";
	identify(&(*ptr));

	delete ptr;

	Base *base = new Base;

	std::cout << "Identify using pointer: ";
	identify(base);

	std::cout << "Identify using reference: ";
	identify(&(*base));

	delete base;

	usleep(900000);

	Base *ptr_the_second = generate();

	std::cout << "Identify using pointer: ";
	identify(ptr_the_second);

	std::cout << "Identify using reference: ";
	identify(&(*ptr_the_second));

	delete ptr_the_second;

	return 0;
}
