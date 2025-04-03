/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:58:05 by tao               #+#    #+#             */
/*   Updated: 2025/03/24 00:00:18 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void upgrade(int &i) {
	i++;
}

void downgrade(int &i) {
	i--;
}


int main() {

	int array[6] = {1, 2, 3, 4, 5, 6};
	char hello_world[11] = {'h', 'e', 'l', 'l', 'o', '_', 'w', 'o', 'r', 'l', 'd'};

	::iter(array, 6, ::show<int>);
	::iter(array, 6, upgrade);
	std::cout << std::endl;
	::iter(array, 6, ::show<int>);
	::iter(array, 3, downgrade);
	std::cout << std::endl;
	::iter(array, 6, ::show<int>);

	std::cout << std::endl;
	::iter(hello_world, 11, ::show<char>);
	std::cout << std::endl;
	::iter(hello_world, 5, ::show<char>);

	return 0;
}
