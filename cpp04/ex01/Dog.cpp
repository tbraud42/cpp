/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:18 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:51:27 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
	return ;
}

Dog::Dog(Dog const &copie) : Animal("Dog")
{
	std::cout << "Dog copie constructor called" << std::endl;
	*this = copie;
	return ;
}

Dog &Dog::operator=(Dog const &copie)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = copie.type;
	this->brain = new Brain(*copie.brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
	return ;
}

void Dog::makeSound() const
{
	std::cout << "bark bark" << std::endl;
	return ;
}

std::string Dog::getIdeas(int i) {
	std::string tmp;
	tmp = this->brain->getIdeas(i);
	if (tmp.empty())
		std::cout << this->type << " don't have idea at [" << i << "]" << std::endl;
	return (tmp);
}

void Dog::setIdeas(std::string idea) {
	if (idea.empty())
		std::cout << this->type << " can't have empty idea" << std::endl;
	if (this->brain->setIdeas(idea))
		std::cout << this->type << " have to much ideas, it can't add a another" << std::endl;
}
