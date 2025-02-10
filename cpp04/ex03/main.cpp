/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:59:42 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 08:06:50 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete tmp
	delete bob;
	delete me;
	delete src;

	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// ICharacter* me = new Character("me");
	// AMateria* trash[2];
	// trash[0] = src->createMateria("ice");
	// me->equip(trash[0]);
	// trash[1] = src->createMateria("cure");
	// me->equip(trash[1]);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);

	// me->unequip(0);
	// me->use(0, *bob);

	// delete trash[0];
	// delete bob;
	// delete me;
	// delete src;

	return 0;
}
