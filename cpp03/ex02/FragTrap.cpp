/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:01:16 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 21:03:20 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_HitPoint = 100;
	this->_EnergyPoint = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &copie) : ClapTrap(copie) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copie;
}

FragTrap &FragTrap::operator=(FragTrap const &copie) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->_name = copie._name;
	this->_HitPoint = copie._HitPoint;
	this->_EnergyPoint = copie._EnergyPoint;
	this->_AttackDamage = copie._AttackDamage;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
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
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "mmmh positive high five" << std::endl;
}
