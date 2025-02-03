/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:37:38 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 21:00:33 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public :

		FragTrap(std::string name);
		FragTrap(FragTrap const &copie);
		FragTrap& operator=(FragTrap const &copie);
		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys(void);

	private :


};
