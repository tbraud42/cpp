/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:50:16 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 07:21:19 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	return ;
}

Ice::Ice(const Ice &copie) : AMateria(copie) {
	*this = copie;
	return ;
}

Ice::~Ice() {
	return ;
}

Ice	&Ice::operator=(const Ice &copie) {
	this->_type = copie.getType();
	return (*this);
}

Ice	*Ice::clone() const {
	if (this->_type != "ice")
		return (NULL);
	Ice *clone = new Ice();
	clone->setType(this->_type);
	return (clone);
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}

