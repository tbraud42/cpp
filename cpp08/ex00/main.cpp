/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/04/02 16:50:19 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main () {
	std::vector<int> vec = {10, 20, 30, 40, 50};

	try {
		auto it = easyfind(vec, 30);
		std::cout << "Trouve dans vector : " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	try {
		auto it = easyfind(vec, 99);
		std::cout << "Trouve dans vector : " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	std::list<int> lst = {5, 15, 25, 35};

	try {
		auto it = easyfind(lst, 15);
		std::cout << "Trouve dans list : " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	try {
		auto it = easyfind(lst, 85);
		std::cout << "Trouve dans list : " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	return 0;
}
