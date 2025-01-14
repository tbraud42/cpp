/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:26:49 by tao               #+#    #+#             */
/*   Updated: 2025/01/10 06:39:50 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("ping pong table");
		HumanA thierry("thierry_henry", club);
		thierry.attack();
		club.setType("");
		thierry.attack();
	}
	{
		Weapon club = Weapon("bed frame");
		HumanB roger("roger_el_log");
		roger.setWeapon(club);
		roger.attack();
		club.setType("");
		roger.attack();
	}
	return 0;
}
