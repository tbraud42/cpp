/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:09 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:29:58 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() : type("") {
	std::cout << "AAnimal default constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(std::string name) : type(name) {
	std::cout << "AAnimal copie constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &copie) {
	std::cout << "AAnimal copie constructor called" << std::endl;
	*this = copie;
	return ;
}

AAnimal &AAnimal::operator=(AAnimal const &copie) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->type = copie.type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
	return ;
}

std::string AAnimal::getType() const {
	return (this->type);
}

void AAnimal::makeSound() const {
	std::cout << "a grouuuu a grouuuu (AAnimal indeterminer)" << std::endl;
	return ;
}
