/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:12:15 by tao               #+#    #+#             */
/*   Updated: 2025/01/07 02:07:58 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	// this->_name = name;
	// this->_weapon = Weapon();
}

HumanB::~HumanB(void) {

}

void HumanB::attack(void) {
	if ((this->_weapon->getType()).empty())
		std::cout << this->_name << " has no weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << (this->_weapon->getType()) << std::endl;
}


void HumanB::setWeapon(Weapon & weapon) {
	this->_weapon = &weapon;
}

