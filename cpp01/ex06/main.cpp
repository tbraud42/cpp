/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:26:49 by tao               #+#    #+#             */
/*   Updated: 2025/01/12 18:48:19 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "invalid number of parameter" << std::endl;
		return (1);
	}

	Harl harl;
	std::string level = av[1];

	harl.complain(level);

	return (0);
}
