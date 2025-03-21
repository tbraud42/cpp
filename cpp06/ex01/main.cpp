/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:58:05 by tao               #+#    #+#             */
/*   Updated: 2025/03/20 06:24:13 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(int ac, char **av) {

	Data newBorn;
	uintptr_t tmp;
	Data *result;

	std::cout << newBorn;
	tmp = serialize(&newBorn);
	result = deserialize(tmp);
	std::cout << *result;
	return 0;
}
