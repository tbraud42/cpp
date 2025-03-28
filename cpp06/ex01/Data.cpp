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

Data::Data(Data const &copie) : i(93) {
	tab[0] = "eat";
	tab[1] = "vegetables";
	return ;
}

Data &Data::operator=(Data const &copie) {
	return *this;
}

Data::~Data() {
	return ;
}

uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

std::ostream &operator<<(std::ostream &out, const Data &Data) {
	std::cout << Data.tab[0] << ' ' << Data.tab[1] << " , " << Data.i << std::endl;
	return out;
}
