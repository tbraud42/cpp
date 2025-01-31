/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:21:36 by tao               #+#    #+#             */
/*   Updated: 2025/01/30 03:10:35 by tao              ###   ########.fr       */
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

	return ;
}

void	PhoneBook::ft_add(void) {
	std::string	info[5];
	std::string	input;

	ft_print_header(1);
	std::cout << "first name" << std::endl;
	std::cin >> info[0];
	if (!std::cin.good())
		exit(1);

	ft_print_header(1);
	std::cout << "last name" << std::endl;
	std::cin >> info[1];
	if (!std::cin.good())
		exit(1);

	ft_print_header(1);
	std::cout << "nikname" << std::endl;
	std::cin >> info[2];
	if (!std::cin.good())
		exit(1);

	ft_print_header(1);
	std::cout << "phone number" << std::endl;
	std::cin >> info[3];
	if (!std::cin.good())
		exit(1);

	ft_print_header(1);
	std::cout << "darkest secret" << std::endl;
	std::cin >> info[4];
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
		std::cin >> input;
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

std::string ft_resize_string(std::string str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	ft_print_search(int i, std::string info[5]) {
	if (!info[0][0])
		return (1);

	std::cout << "|" << std::setw(10);
	std::cout << i + 1;
	std::cout << "|" << std::setw(10);
	std::cout << ft_resize_string(info[0]);
	std::cout << "|" << std::setw(10);
	std::cout << ft_resize_string(info[1]);
	std::cout << "|" << std::setw(10);
	std::cout << ft_resize_string(info[2]);
	std::cout << "|" << std::endl;

	return (0);
}

int	ft_display_search(Contact *contact) {
	int	i = 0;

	system("clear");
	std::cout << ",-------------------------------------------," << std::endl;
	while (i < 8) {
		if (ft_print_search(i, contact[i].GetContact()))
			break ;
		i++;
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

	std::cin >> input;
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

	std::cin >> input;
	if (!std::cin.good())
		exit(1);

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

	std::cin >> input;
	if (!std::cin.good())
		exit(1);

	i = std::atoi(&input[0]);
	while (i < 1 || i > num_contact || ft_find_contact(this->GetPhoneBook(), i)) {
		ft_display_search(this->GetPhoneBook());
		if (i == 0 || i == -1)
			std::cout << "wrong input" << std::endl;
		else
			std::cout << "no contact " << i << " save yet" << std::endl;
		if (i == 1)
			std::cout << "which contact would you like to see [1] : ";
		else
			std::cout << "which contact would you like to see [1:" << num_contact << "] : ";
		std::cin >> input;
		if (!std::cin.good())
			exit(1);
		i = std::atoi(&input[0]);
	}

	return ;
}

int	main(void) {
	std::string	input;


	PhoneBook contact;
	while (1) {
		ft_print_header(0);
		std::cout << "choose me (kawai)" << std::endl;
		std::cin >> input;
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

