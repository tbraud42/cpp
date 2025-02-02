/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 06:07:47 by tao               #+#    #+#             */
/*   Updated: 2025/02/01 00:07:29 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	return ;
}

Harl::~Harl() {
	return ;
}

void Harl::debug( void ) {
	std::cout << std::endl << "I love having 7XL-double-cheese supplement \"my big burger mmmh\". I really do!" << std::endl;
	return ;
}

void Harl::info( void ) {
	std::cout << std::endl << "I cannot believe adding extra bacon costs more money. You didn t put enough bacon in my burger! If you did, I wouldn t be asking for more!" << std::endl;
	return ;
}

void Harl::warning( void ) {
	std::cout << std::endl << "I think I deserve to have some extra bacon for free. I ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void Harl::error( void ) {
	std::cout << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void Harl::complain( std::string level ) {
	std::string choice[4];
	choice[0] = "DEBUG";
	choice[1] = "INFO";
	choice[2] = "WARNING";
	choice[3] = "ERROR";

	int i = 0;

	while (i < 4 && level.compare(choice[i]))
		i++;

	i++;
	switch (i)
	{
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
			std::cout << std::endl;
			/* fall through */
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			this->info();
			std::cout << std::endl;
			/* fall through */
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
			std::cout << std::endl;
			/* fall through */
		case 4:
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return ;
}

