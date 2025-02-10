/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 03:21:48 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 06:52:20 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "ICharacter.hpp"

class Character : public ICharacter {

	public :

		Character();
		Character(std::string type);
		Character(const Character &obj);
		Character &operator=(const Character &obj);
		~Character();

		AMateria *getInv(int i) const;
		std::string const &getName() const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private :

		std::string _name;
		AMateria *_inventory[4];
};
