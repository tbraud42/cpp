/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 01:40:02 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 07:26:18 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_src[i] = NULL;
	}
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &copie) {
	for (int i = 0; i < 4; i++) {
		if (copie._src[i])
			this->_src[i] = copie._src[i]->clone();
		else
			this->_src[i] = NULL;
	}
	return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copie) {
	if (this != &copie) {
		for (int i = 0; i < 4; i++) {
			if (this->_src[i]) {
				delete this->_src[i];
				this->_src[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (copie._src[i])
				this->_src[i] = copie._src[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_src[i])
			delete this->_src[i];
	}
	return ;
}

AMateria	*MateriaSource::getSrc(int i) const {
	return (this->_src[i]);
}

void	MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->_src[i] == NULL) {
			this->_src[i] = m->clone();
			delete m;
			return;
		}
	}
	std::cout << "Not enough space to learn a Materia" << std::endl;
	delete m;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_src[i] && this->_src[i]->getType() == type) {
			return (this->_src[i]->clone());
		}
	}
	std::cout << "Materia " << type << " not learned"<< std::endl;
	return (0);
}
