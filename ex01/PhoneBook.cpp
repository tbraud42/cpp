/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:21:36 by tao               #+#    #+#             */
/*   Updated: 2024/10/02 22:30:14 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_index = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::SetInfo(std::string info[5]) {
	this->_info[0] = info[0];
	this->_info[1] = info[1];
	this->_info[2] = info[2];
	this->_info[3] = info[3];
	this->_info[4] = info[4];
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
	std::string info[5];
	std::string input;

	ft_print_header(1);
	std::cout << "first name" << std::endl;
	std::cin >> info[0];
	ft_print_header(1);
	std::cout << "last name" << std::endl;
	std::cin >> info[1];
	ft_print_header(1);
	std::cout << "nikname" << std::endl;
	std::cin >> info[2];
	ft_print_header(1);
	std::cout << "phone number" << std::endl;
	std::cin >> info[3];
	ft_print_header(1);
	std::cout << "darkest secret" << std::endl;
	std::cin >> info[4];
	this->_info[this->_index].SetInfo(info);	
	this->_index++;
	if (this->_index == 8)
		this->_index = 0;
	ft_print_header(1);
	std::cout << "contact successfully added" << std::endl;
	while(1) {
		std::cout << "do you want to add another contact? y/n" << std::endl;
		std::cin >> input;
		for (int j = 0; input[j]; j++)
			input[j] = std::toupper(input[j]);
		if (input.compare("Y") == 0 || input.compare("YES") == 0) {
			this->ft_add();
			return ;
		}
		if (input.compare("N") == 0 || input.compare("NO") == 0)
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
			contact.ft_add();
		else if (decision.compare("SEARCH") == 0)
			contact.ft_search(); // suce mon enorme queue
		else if (decision.compare("EXIT") == 0)
			return (0);
		else { // doute ,  c'est mieux sans ?
			std::cout << "impossible request" << std::endl;
			usleep(600000);
		}
	}
	return 0;
}
