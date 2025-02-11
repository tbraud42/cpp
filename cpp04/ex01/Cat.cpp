/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:13 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:51:03 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
	return ;
}

Cat::Cat(Cat const &copie) : Animal("Cat") {
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

std::string Cat::getIdeas(int i) {
	std::string tmp;
	tmp = this->brain->getIdeas(i);
	if (tmp.empty())
		std::cout << this->type << " don't have idea at [" << i << "]" << std::endl;
	return (tmp);
}

void Cat::setIdeas(std::string idea) {
	if (idea.empty())
		std::cout << this->type << " can't have empty idea" << std::endl;
	if (this->brain->setIdeas(idea))
		std::cout << this->type << " have to much ideas, it can't add a another" << std::endl;
}
