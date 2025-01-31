/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:12:27 by tao               #+#    #+#             */
/*   Updated: 2025/01/31 19:15:10 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {

	public :

		HumanB(std::string name);
		~HumanB(void);

		void attack(void);
		void setWeapon(Weapon & weapon);

	private :

		std::string _name;
		Weapon * _weapon = NULL;

};
