/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:26:20 by tao               #+#    #+#             */
/*   Updated: 2025/01/04 02:22:12 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <new>

class Zombie {

	public :

		Zombie(void);
		~Zombie(void);

		void announce(void);
		void setName(std::string name);
		Zombie* zombieHorde(int N, std::string name);

	private :

		std::string	_name;

};

