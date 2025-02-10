/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:41:51 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 06:51:18 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	return ;
}

AMateria::AMateria(const AMateria &obj) {
	*this = obj;
	return ;
}

AMateria::~AMateria(void) {
	return ;
}

AMateria	&AMateria::operator=(const AMateria &obj) {
	this->_type = obj.getType();
	return (*this);
}

std::string const	&AMateria::getType(void) const {
	return (this->_type);
}

void	AMateria::setType(std::string type) {
	this->_type = type;
	return ;
}

void	AMateria::use(ICharacter &target) {
	(void)target;
	return ;
}
