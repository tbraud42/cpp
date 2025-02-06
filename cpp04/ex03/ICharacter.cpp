/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:58:14 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:59:08 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

std::string const &ICharacter::getName() const {

}

void ICharacter::equip(AMateria *m) {

}

void ICharacter::unequip(int idx) {

}

void ICharacter::use(int idx, ICharacter &target) {

}

ICharacter::~ICharacter() {
	// std::cout << "ICharacter destructor called" << std::endl;
}
