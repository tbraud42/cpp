/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:39:55 by tbraud            #+#    #+#             */
/*   Updated: 2025/04/18 15:40:24 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	return ;
}

Serializer::Serializer(Serializer const &copie) {
	return ;
}

Serializer &Serializer::operator=(Serializer const &copie) {
	return *this;
}

Serializer::~Serializer() {
	return ;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}