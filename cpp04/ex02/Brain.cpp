/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:09:22 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 17:02:27 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(Brain const &copie) {
	std::cout << "Brain copie constructor called" << std::endl;
	*this = copie;
	return ;
}

Brain &Brain::operator=(Brain const &copie) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &copie) {
		for (int i = 0; i < 100; i++)
			ideas[i] = copie.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
	return ;
}
