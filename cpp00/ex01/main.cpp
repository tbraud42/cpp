/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:47:26 by tao               #+#    #+#             */
/*   Updated: 2025/01/31 23:47:51 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
