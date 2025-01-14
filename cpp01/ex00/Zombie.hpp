/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:26:06 by tao               #+#    #+#             */
/*   Updated: 2025/01/04 02:23:42 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie {

	public :

		Zombie(std::string name);
		~Zombie(void);

		void announce(void);

		void randomChump( std::string name );

		Zombie *newZombie(std::string name);
	private :

		std::string	_name;

};

