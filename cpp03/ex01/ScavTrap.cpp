#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:01:16 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 19:01:17 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ScavTrap::ScavTrap(std::string name) {
	std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copie) {
	std::cout << "Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copie) {
	std::cout << "Copy assignment operator called" << std::endl;
	// TODO: insert return statement here
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor called" << std::endl;
}
