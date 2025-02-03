/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:01:16 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 21:03:43 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_HitPoint = 100;
	this->_EnergyPoint = 50;
	this->_AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &copie) : ClapTrap(copie) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copie;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copie) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->_name = copie._name;
	this->_HitPoint = copie._HitPoint;
	this->_EnergyPoint = copie._EnergyPoint;
	this->_AttackDamage = copie._AttackDamage;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (!target[0])
	{
		std::cout << this->_name << "can't attack anyone or anything" << std::endl;
		return ;
	}
	if (this->_EnergyPoint == 0)
	{
		std::cout << this->_name << "doesn't have enough energy points to attack" << std::endl;
		return ;
	}
	else
		this->_EnergyPoint--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
