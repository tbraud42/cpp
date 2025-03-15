/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:47:26 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 17:34:06 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	ft_print_header(int i) {
	system("clear");
	if (i == 0) {
		std::cout << ",-----------------------------------------," << std::endl;
		std::cout << "|               PHONE BOOK                |" << std::endl;
		std::cout << "|           ADD   SEARCH   EXIT           |" << std::endl;
		std::cout << "'-----------------------------------------'" << std::endl;
	}
	else if (i == 1) {
		std::cout << ",-----------------------------------------," << std::endl;
		std::cout << "|               PHONE BOOK                |" << std::endl;
		std::cout << "|                MODE ADD                 |" << std::endl;
		std::cout << "'-----------------------------------------'" << std::endl;
	}

	return ;
}

std::string ft_resize_string(std::string str) {

	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	ft_print_search(int i, std::string info[5]) {

	std::cout << "|" << std::setw(10);
	std::cout << i + 1;
	std::cout << "|" << std::setw(10);
	std::cout << ft_resize_string(info[0]);
	std::cout << "|" << std::setw(10);
	std::cout << ft_resize_string(info[1]);
	std::cout << "|" << std::setw(10);
	std::cout << ft_resize_string(info[2]);
	std::cout << "|" << std::endl;
}

int	ft_display_search(Contact *contact) {
	int	i = 0;

	system("clear");
	std::cout << ",-------------------------------------------," << std::endl;
	while (i < 8 && contact[i].GetContact()[0][0]) {
		ft_print_search(i, contact[i].GetContact());
		++i;
	}
	std::cout << "'-------------------------------------------'" << std::endl;

	return (i);
}

int ft_find_contact(Contact *contact, int i) {
	unsigned int	size_col = 10;
	std::string		*info;
	std::string		input;

	info = contact[i - 1].GetContact();
	for (int j = 0; j < 8; j++) {
		if (info[j].size() > size_col) {
			size_col = info[j].size();
		}
	}

	system("clear");
	std::cout << ",";
	if (size_col > 50)
		size_col = 50;
	for (unsigned int j = 0; j < size_col; j++) {
		std::cout << "-";
	}

	std::cout << "," << std::endl;
	std::cout << "|" << std::setw(size_col) << info[0] << "|" << std::endl;
	std::cout << "|" << std::setw(size_col) << info[1] << "|" << std::endl;
	std::cout << "|" << std::setw(size_col) << info[2] << "|" << std::endl;
	std::cout << "|" << std::setw(size_col) << info[3] << "|" << std::endl;
	std::cout << "|" << std::setw(size_col) << info[4] << "|" << std::endl;
	std::cout << "'";

	for (unsigned int j = 0; j < size_col; j++) {
		std::cout << "-";
	}
	std::cout << "'" << std::endl;
	std::cout << "write anything to return to main menu : ";

	std::getline(std::cin, input);
	if (!std::cin.good())
		exit(1);

	return (0);
}

void	ft_contact_empty(void) {
	std::string	input;

	system("clear");
	std::cout << ",---------------------------------------," << std::endl;
	std::cout << "|    you have no registered contacts    |" << std::endl;
	std::cout << "'---------------------------------------'" << std::endl;
	std::cout << "write anything to return to main menu : ";

	std::getline(std::cin, input);
	if (!std::cin.good())
		exit(1);

	return ;
}

int	main(void) {
	std::string	input;

	PhoneBook contact;
	while (1) {
		ft_print_header(0);
		std::cout << "choose mode" << std::endl;
		std::getline(std::cin, input);
		if (!std::cin.good())
			return (1);
		if (input.compare("ADD") == 0)
			contact.ft_add();
		else if (input.compare("SEARCH") == 0)
			contact.ft_search();
		else if (input.compare("EXIT") == 0)
			return (0);
	}
	return (0);
}
