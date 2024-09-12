/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:21:36 by tao               #+#    #+#             */
/*   Updated: 2024/09/12 01:19:45 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	main(void) {
	char	test[20];
	PhoneBook instance;
	usleep(500000);
	system("clear");
	std::cout << "___________________________________________" << std::endl;
	std::cout << "|             bonjour enfant               |" << std::endl;
	std::cout << "___________________________________________" << std::endl;
	std::cout << "___________________________________________" << std::endl;
	std::cout << "___________________________________________" << std::endl;
	std::cout << "___________________________________________" << std::endl;
	std::cout << "give me your children ? yes/no" << std::endl;
	std::cin >> test;


	return 0;
}
