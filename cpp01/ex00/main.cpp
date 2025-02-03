/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:25:36 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 17:31:31 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){

	std::cout << "=========================" << std::endl;
	randomChump("roger");
	std::cout << "=========================" << std::endl;

	Zombie *sylvie = NULL;
	{
		sylvie = newZombie("sylvie");
	}
	std::cout << "=========================" << std::endl;
	sylvie->announce();
	delete sylvie;
	std::cout << "=========================" << std::endl;

	return 0;
}
