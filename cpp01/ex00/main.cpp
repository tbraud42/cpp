/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:25:36 by tao               #+#    #+#             */
/*   Updated: 2025/01/03 03:11:26 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){

	Zombie *roger = NULL;
	roger->randomChump("roger");

	Zombie *sylvie = NULL;
	sylvie = sylvie->newZombie("sylvie");

	delete sylvie;

	return 0;
}
