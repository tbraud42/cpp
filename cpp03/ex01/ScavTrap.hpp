/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:37:38 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 19:39:07 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public :

		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &copie);
		ScavTrap& operator=(ScavTrap const &copie);
		~ScavTrap();

	private :


};
