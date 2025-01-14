/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 06:07:47 by tao               #+#    #+#             */
/*   Updated: 2025/01/12 17:15:29 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {

}
Harl::~Harl() {

}

void Harl::debug( void ) {
	std::cout << "I love having 7XL-double-cheese supplement \"my big burger mmmh\". I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn t put enough bacon in my burger! If you did, I wouldn t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
	void (Harl::*functionPtr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string choice[4];
	choice[0] = "DEBUG";
	choice[1] = "INFO";
	choice[2] = "WARNING";
	choice[3] = "ERROR";
	for (int i = 0; i < 4; i++) {
		if (!level.compare(choice[i])) {
			(this->*functionPtr[i])();
			return ;
		}
	}
	std::cout << "mode not found" << std::endl;
}

