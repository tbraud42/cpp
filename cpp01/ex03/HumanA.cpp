/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:12:20 by tao               #+#    #+#             */
/*   Updated: 2025/01/07 02:14:13 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {

}

HumanA::~HumanA(void) {

}

void HumanA::attack(void) {
	if ((this->_weapon.getType()).empty())
		std::cout << this->_name << " has no weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << (this->_weapon.getType()) << std::endl;
}
