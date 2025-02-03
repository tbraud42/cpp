/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:34 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 20:51:19 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {

	ScavTrap bernard("bernard");
	ScavTrap sylvie("sylvie");

	bernard.attack("");
	bernard.attack("sylvie");
	sylvie.takeDamage(0);

}
