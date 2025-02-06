/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:13 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:29:12 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
	return ;
}

Cat::Cat(Cat const &copie) : AAnimal("Cat") {
	std::cout << "Cat copie constructor called" << std::endl;
	*this = copie;
	return ;
}

Cat &Cat::operator=(Cat const &copie) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = copie.type;
	this->brain = new Brain(*copie.brain);
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
	return ;
}

void Cat::makeSound() const{
	std::cout << "grrrrrr" << std::endl;
	return ;
}
