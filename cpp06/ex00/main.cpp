/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:58:05 by tao               #+#    #+#             */
/*   Updated: 2025/04/18 15:50:05 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {

	if (ac != 2) {std::cout << "wrong number of argument" << std::endl; return 1;}

	ScalarConverter::convert((std::string)av[1]);

	return 0;
}
