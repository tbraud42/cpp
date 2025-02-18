/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:52:49 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 07:00:37 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria{

	public :

		Cure();
		Cure(std::string const & type);
		Cure(Cure const &copie);
		Cure& operator=(Cure const &copie);
		~Cure();

		Cure *clone() const;
		void use(ICharacter& target);

};
