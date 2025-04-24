/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:58:05 by tao               #+#    #+#             */
/*   Updated: 2025/04/18 15:43:34 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char **av) {

	Data newBorn;
	uintptr_t tmp;
	Data *result;


	std::cout << newBorn << " adress = " << &newBorn << std::endl;
	tmp = Serializer::serialize(&newBorn);
	result = Serializer::deserialize(tmp);
	std::cout << *result << " adress = " << result << std::endl;
	return 0;
}
