/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:30:25 by tao               #+#    #+#             */
/*   Updated: 2025/01/03 22:03:31 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name ) {

	if (N < 0)
		return NULL;

	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}

	return horde;
}
