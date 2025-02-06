/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:58:14 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 04:33:47 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

std::string const &ICharacter::getName() const {
	retrun this->name;
}

void ICharacter::equip(AMateria *m) {

}

void ICharacter::unequip(int idx) {

}

void ICharacter::use(int idx, ICharacter &target) {

}
