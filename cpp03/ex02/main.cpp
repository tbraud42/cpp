/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:34 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 01:25:26 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap *original = new ClapTrap("original");
	ClapTrap *copie = new ClapTrap(*original);

	delete copie;
	delete original;
	// FragTrap bernard("bernard");
	// FragTrap sylvie("sylvie");

	// bernard.attack("");
	// bernard.attack("sylvie");
	// sylvie.takeDamage(0);

}
