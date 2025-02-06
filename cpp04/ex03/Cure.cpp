/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:52:26 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:59:16 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(std::string const &type) {
	// std::cout << "Cure default constructor called" << std::endl;
	return ;
}


Cure::Cure(Cure const &copie) {
	// std::cout << "Cure copie constructor called" << std::endl;
	*this = copie;
	return ;
}

Cure &Cure::operator=(Cure const &copie) {
	// std::cout << "Cure copy assignment operator called" << std::endl;

}

Cure::~Cure() {
	// std::cout << "Cure destructor called" << std::endl;
}
