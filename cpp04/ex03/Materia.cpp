#include "Materia.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:41:51 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:41:52 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {
	// std::cout << "AMateria default constructor called" << std::endl;
	return ;
}


AMateria::AMateria(AMateria const &copie) {
	// std::cout << "AMateria copie constructor called" << std::endl;
	*this = copie;
	return ;
}

AMateria &AMateria::operator=(AMateria const &copie) {
	// std::cout << "AMateria copy assignment operator called" << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destructor called" << std::endl;
}
