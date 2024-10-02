/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:21:36 by tao               #+#    #+#             */
/*   Updated: 2024/10/02 15:21:29 by tao              ###   ########.fr       */
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

void	ft_print_header(int i) {
	system("clear");
	if (i == 0) {
		std::cout << ",-----------------------------------------," << std::endl;
		std::cout << "|               PHONE BOOK                |" << std::endl;
		std::cout << "|            SI SI LA FAMILLE             |" << std::endl;
		std::cout << "|                                         |" << std::endl;
		std::cout << "|              brevet deposé              |" << std::endl;
		std::cout << "'-----------------------------------------'" << std::endl;
	}
	else if (i == 1) {
		std::cout << ",-----------------------------------------," << std::endl;
		std::cout << "|               PHONE BOOK                |" << std::endl;
		std::cout << "|            SI SI LA FAMILLE             |" << std::endl;
		std::cout << "|                MODE ADD                 |" << std::endl;
		std::cout << "|              brevet deposé              |" << std::endl;
		std::cout << "'-----------------------------------------'" << std::endl;
	}
	else if (i == 2) {
		std::cout << ",-----------------------------------------," << std::endl;
		std::cout << "|               PHONE BOOK                |" << std::endl;
		std::cout << "|            SI SI LA FAMILLE             |" << std::endl;
		std::cout << "|                MODE SEARCH              |" << std::endl;
		std::cout << "|              brevet deposé              |" << std::endl;
		std::cout << "'-----------------------------------------'" << std::endl;
	}
}

void	PhoneBook::ft_add(void) {
	std::string info;

	ft_print_header(1);
	std::cout << "first name" << std::endl;
	std::cin >> info;
	this->f_name = info;
	ft_print_header(1);
	std::cout << "last name" << std::endl;
	std::cin >> info;
	this->l_name = info;
	ft_print_header(1);
	std::cout << "nikname" << std::endl;
	std::cin >> info;
	this->n_name = info;
	ft_print_header(1);
	std::cout << "phone number" << std::endl;
	std::cin >> info;
	this->num = info;
	ft_print_header(1);
	std::cout << "darkest secret" << std::endl;
	std::cin >> info;
	this->secret = info;
	ft_print_header(1);
	std::cout << "contact successfully added" << std::endl;
	while(1) {
		std::cout << "do you want to add another contact? y/n" << std::endl;
		std::cin >> info;
		for (int j = 0; info[j]; j++)
			std::cout << (char)std::toupper(info[j]);
		if (info.compare("Y") == 0 || info.compare("YES") == 0) {
			this->ft_add();
			return ;
		}
		if (info.compare("N") == 0 || info.compare("NO") == 0)
			return ;
		ft_print_header(1);
	}
}

void	PhoneBook::ft_search() {
	return ;
}

int	main(void) {
	std::string decision;

	PhoneBook contact;
	while (1) {
		ft_print_header(0);
		std::cout << "choose me (kawai)" << std::endl;
		std::cin >> decision;
		if (decision.compare("ADD") == 0)
			contact.ft_add(); // suce mon enorme queue
		else if (decision.compare("SEARCH") == 0)
			contact.ft_search(); // suce mon enorme queue
		else if (decision.compare("EXIT") == 0)
			return (0);
		else {
			std::cout << "impossible request" << std::endl;
			sleep(0.4);
		}
	}
	return 0;
}
