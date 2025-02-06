/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:34 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 15:37:40 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap bernard("bernard");
	ClapTrap sylvie("sylvie");

	bernard.attack("");
	bernard.attack("sylvie");
	sylvie.takeDamage(0);
	sylvie.attack("roger");
	

	return (0);
}
