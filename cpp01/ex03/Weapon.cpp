/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:12:42 by tao               #+#    #+#             */
/*   Updated: 2025/01/07 02:11:59 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon(void) {

}

const std::string& Weapon::getType(void) {
	return this->_type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
