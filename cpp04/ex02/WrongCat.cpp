/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:13 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:55:25 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->brain = new Brain();
	return ;
}

WrongCat::WrongCat(WrongCat const &copie) : WrongAAnimal("WrongCat") {
	std::cout << "WrongCat copie constructor called" << std::endl;
	*this = copie;
	return ;
}

WrongCat &WrongCat::operator=(WrongCat const &copie) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->type = copie.type;
	this->brain = new Brain(*copie.brain);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
	delete this->brain;
	return ;
}

void WrongCat::makeSound() const{
	std::cout << "grrrrrr" << std::endl;
	return ;
}

std::string WrongCat::getIdeas(int i) {
	std::string tmp;
	tmp = this->brain->getIdeas(i);
	if (tmp.empty())
		std::cout << "I don't have idea at [" << i << "]" << std::endl;
	return (tmp);
}

void WrongCat::setIdeas(std::string idea) {
	if (idea.empty())
		std::cout << this->type << " can't have empty idea" << std::endl;
	if (this->brain->setIdeas(idea))
		std::cout << this->type << " have to much ideas, it can't add a another" << std::endl;
}
