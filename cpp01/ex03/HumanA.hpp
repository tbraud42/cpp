/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:12:49 by tao               #+#    #+#             */
/*   Updated: 2025/01/07 02:13:43 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {

	public :

		HumanA(std::string name, Weapon & weapon);
		~HumanA(void);

		void attack(void);

	private :

		std::string _name;
		Weapon & _weapon;

};
