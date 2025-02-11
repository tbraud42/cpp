/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:09 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:54:44 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal() : type("") {
	std::cout << "WrongAAnimal default constructor called" << std::endl;
	return ;
}

WrongAAnimal::WrongAAnimal(std::string name) : type(name) {
	std::cout << "WrongAAnimal default constructor called" << std::endl;
	return ;
}

WrongAAnimal::WrongAAnimal(WrongAAnimal const &copie) {
	std::cout << "WrongAAnimal copie constructor called" << std::endl;
	*this = copie;
}

WrongAAnimal &WrongAAnimal::operator=(WrongAAnimal const &copie) {
	std::cout << "WrongAAnimal copy assignment operator called" << std::endl;
	this->type = copie.type;
	return (*this);
}

WrongAAnimal::~WrongAAnimal() {
	std::cout << "WrongAAnimal destructor called" << std::endl;
}

std::string WrongAAnimal::getType() const {
	return (this->type);
}

void WrongAAnimal::makeSound() const {
	std::cout << "a grouuuu a grouuuu (WrongAAnimal indeterminer)" << std::endl;
}
