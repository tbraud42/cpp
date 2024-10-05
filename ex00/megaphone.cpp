/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:30:41 by tbraud            #+#    #+#             */
/*   Updated: 2024/10/05 02:57:02 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int	i;

	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	i = 1;
	while (av[i] && av[i][0] == '\0')
		i++;
	if (i == ac) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int k = i; k < ac; k++) {
		if (av[k][0]) {
			for (int j = 0; av[k][j]; j++)
				std::cout << (char)std::toupper(av[k][j]);
		}
	}
	std::cout << std::endl;
	return 0;
}
