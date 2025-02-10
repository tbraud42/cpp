/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:41:53 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 06:51:37 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

	protected :

		std::string _type;

	public :

		AMateria(std::string const & type);
		AMateria();
		AMateria(AMateria const &copie);
		AMateria& operator=(AMateria const &copie);
		virtual ~AMateria();

		void setType(std::string type);
		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};
