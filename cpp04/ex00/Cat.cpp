/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:13 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 01:31:16 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &copie) : Animal("Cat") {
	std::cout << "Cat copie constructor called" << std::endl;
	*this = copie;
}

Cat &Cat::operator=(Cat const &copie) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = copie.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "grrrrrr" << std::endl;
}
