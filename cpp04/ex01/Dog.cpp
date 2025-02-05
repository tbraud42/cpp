/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:18 by tao               #+#    #+#             */
/*   Updated: 2025/02/05 01:42:18 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &copie) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	*this = copie;
}

Dog &Dog::operator=(Dog const &copie) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = copie.type;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "bark bark" << std::endl;
}
