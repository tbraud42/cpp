/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:58:05 by tao               #+#    #+#             */
/*   Updated: 2025/03/16 21:16:38 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {

	if (ac != 2) {std::cout << "wrong number of argument" << std::endl; return 1;}

	ScalarConverter converterMonster;

	converterMonster.stringToChar(av[1]);
	converterMonster.stringToInt(av[1]);
	converterMonster.stringToFloat(av[1]);
	converterMonster.stringToDouble(av[1]);

	return 0;
}
