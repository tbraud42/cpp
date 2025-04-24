/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 01:08:22 by tao               #+#    #+#             */
/*   Updated: 2025/03/20 00:03:14 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : i(93) {
	tab[0] = "eat";
	tab[1] = "vegetables";
	return ;
}

Data::Data(Data const &copie) {
	*this = copie;
	return ;
}

Data &Data::operator=(Data const &copie) {
	this->i = copie.i;
	this->tab[0] = copie.tab[0];
	this->tab[1] = copie.tab[1];
	return *this;
}

Data::~Data() {
	return ;
}

std::ostream &operator<<(std::ostream &out, const Data &Data) {
	std::cout << Data.tab[0] << ' ' << Data.tab[1] << " , " << Data.i;
	return out;
}
