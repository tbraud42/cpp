/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:52:26 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 06:53:08 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	return ;
}

Cure::Cure(const Cure &copie) : AMateria(copie) {
	*this = copie;
	return ;
}

Cure::~Cure() {
	return ;
}

Cure	&Cure::operator=(const Cure &copie) {
	this->_type = copie.getType();
	return (*this);
}

Cure	*Cure::clone() const {
	if (this->_type != "cure")
		return (NULL);
	Cure *tmp = new Cure();
	tmp->setType(this->_type);
	return (tmp);
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
