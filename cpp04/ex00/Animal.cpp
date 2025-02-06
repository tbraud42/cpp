/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:09 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 01:31:10 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(std::string name) : type(name) {
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const &copie) {
	std::cout << "Animal copie constructor called" << std::endl;
	*this = copie;
}

Animal &Animal::operator=(Animal const &copie) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = copie.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}

void Animal::makeSound() const {
	std::cout << "a grouuuu a grouuuu (animal indeterminer)" << std::endl;
}
