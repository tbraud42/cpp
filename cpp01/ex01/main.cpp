/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:26:49 by tao               #+#    #+#             */
/*   Updated: 2025/01/04 00:34:37 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

	int	numHorde = 5;

	Zombie *herve = NULL;
	herve = herve->zombieHorde(numHorde, "herve");
	Zombie *joshua = herve;
	while (numHorde > 0)
	{
		joshua->announce();
		joshua++;
		numHorde--;
	}

	delete [] herve;

	return 0;
}
