/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:18 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:29:12 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
	return ;
}

Dog::Dog(Dog const &copie) : AAnimal("Dog") {
	std::cout << "Dog copie constructor called" << std::endl;
	*this = copie;
	return ;
}

Dog &Dog::operator=(Dog const &copie) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = copie.type;
	this->brain = new Brain(*copie.brain);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
	return ;
}

void Dog::makeSound() const {
	std::cout << "bark bark" << std::endl;
	return ;
}
