/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:41:53 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 04:02:47 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria {

	protected :

		std::string _type;

	public :

		AMateria(std::string const & type);
		AMateria(AMateria const &copie);
		AMateria& operator=(AMateria const &copie);
		~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};
