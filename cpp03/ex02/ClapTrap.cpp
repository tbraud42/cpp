/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:25:22 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 16:30:19 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &copie) {
	std::cout << "ClapTrap copie constructor called" << std::endl;
	*this = copie;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &copie) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->_name = copie._name;
	this->_HitPoint = copie._HitPoint;
	this->_EnergyPoint = copie._EnergyPoint;
	this->_AttackDamage = copie._AttackDamage;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (!target[0]) {
		std::cout << this->_name << "can't attack anyone or anything" << std::endl;
		return ;
	}

	if (this->_EnergyPoint == 0) {
		std::cout << this->_name << "doesn't have enough energy points to attack" << std::endl;
		return ;
	} else
		this->_EnergyPoint--;

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;

	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_HitPoint <= amount) {
		this->_HitPoint = 0;
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	} else {
		this->_HitPoint -= amount;
	}

	return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_EnergyPoint == 0) {
		std::cout << this->_name << "doesn't have enough energy points to repaired himself" << std::endl;
		return ;
	} else
		this->_EnergyPoint--;

	this->_HitPoint += amount;

	return ;
}
