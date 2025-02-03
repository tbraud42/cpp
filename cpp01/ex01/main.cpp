/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:26:49 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 18:20:43 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

	int	numHorde = 5;

	Zombie *herve = NULL;
	{
		herve = zombieHorde(numHorde, "herve");
	}

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
