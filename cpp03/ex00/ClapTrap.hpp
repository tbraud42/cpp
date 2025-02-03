/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:54 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 18:00:09 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {

	public :

		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copie);
		ClapTrap& operator=(ClapTrap const &copie);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private :

		std::string		_name;
		unsigned int	_HitPoint;
		unsigned int	_EnergyPoint;
		unsigned int	_AttackDamage;

};
