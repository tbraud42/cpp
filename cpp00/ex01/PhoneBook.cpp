/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:21:36 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 00:58:10 by tao              ###   ########.fr       */
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

Contact *PhoneBook::GetPhoneBook(void) {
	return (this->_info);
}

void	PhoneBook::ft_add(void) {
	std::string	info[5];
	std::string	input;

	while (1) {
		ft_print_header(1);
		std::cout << "first name" << std::endl;
		std::getline(std::cin, info[0]);
		if (!std::cin.good())
			exit(1);
		if (!info[0].empty())
			break ;
	}


	ft_print_header(1);
	std::cout << "last name" << std::endl;
	std::getline(std::cin, info[1]);
	if (!std::cin.good())
		exit(1);

	ft_print_header(1);
	std::cout << "nikname" << std::endl;
	std::getline(std::cin, info[2]);
	if (!std::cin.good())
		exit(1);

	ft_print_header(1);
	std::cout << "phone number" << std::endl;
	std::getline(std::cin, info[3]);
	if (!std::cin.good())
		exit(1);

	ft_print_header(1);
	std::cout << "darkest secret" << std::endl;
	std::getline(std::cin, info[4]);
	if (!std::cin.good())
		exit(1);

	this->_info[this->_index].SetInfo(info);
	this->_index++;
	if (this->_index == 8)
		this->_index = 0;

	ft_print_header(1);
	std::cout << "contact successfully added" << std::endl;
	while(1) {
		std::cout << "do you want to add another contact? y/n" << std::endl;
		std::getline(std::cin, input);
		if (!std::cin.good())
			exit(1);

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

	return ;
}

void	PhoneBook::ft_search() {
	std::string	input;
	int			i = 0;
	int			num_contact;

	if (!this->_info[0].GetContact()[0][0]) {
		ft_contact_empty();
		return ;
	}

	num_contact = ft_display_search(this->GetPhoneBook());
	if (num_contact == 1)
		std::cout << "which contact would you like to see [1] : ";
	else
		std::cout << "which contact would you like to see [1:" << num_contact << "] : ";

	std::getline(std::cin, input);
	if (!std::cin.good())
		exit(1);

	i = std::atoi(&input[0]);
	while (i < 1 || i > num_contact || ft_find_contact(this->GetPhoneBook(), i)) {
		ft_display_search(this->GetPhoneBook());
		if (i == 0 || i == -1)
			std::cout << "wrong input" << std::endl;
		else
			std::cout << "no contact " << i << " save yet" << std::endl;
		if (num_contact == 1)
			std::cout << "which contact would you like to see [1] : ";
		else
			std::cout << "which contact would you like to see [1:" << num_contact << "] : ";
		std::getline(std::cin, input);
		if (!std::cin.good())
			exit(1);
		i = std::atoi(&input[0]);
	}

	return ;
}

