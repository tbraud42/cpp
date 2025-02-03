/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:26:06 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 17:24:33 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie {

	public :

		Zombie(std::string name);
		~Zombie(void);

		void announce(void);

	private :

		std::string	_name;

};

void randomChump( std::string name );
Zombie *newZombie(std::string name);
