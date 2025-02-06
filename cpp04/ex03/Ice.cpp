/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:50:16 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:59:23 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(std::string const &type) {
	// std::cout << "Ice default constructor called" << std::endl;
	return ;
}


Ice::Ice(Ice const &copie) {
	// std::cout << "Ice copie constructor called" << std::endl;
	*this = copie;
	return ;
}

Ice &Ice::operator=(Ice const &copie) {
	// std::cout << "Ice copy assignment operator called" << std::endl;

}

Ice::~Ice() {
	// std::cout << "Ice destructor called" << std::endl;
}
