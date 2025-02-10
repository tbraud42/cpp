/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:49:18 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 07:00:31 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria{

	public :

		Ice();
		Ice(std::string const & type);
		Ice(Ice const &copie);
		Ice& operator=(Ice const &copie);
		~Ice();

		Ice *clone() const;
		void use(ICharacter& target);

};
