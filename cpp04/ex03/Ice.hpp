/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:49:18 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:55:13 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Materia.hpp"

class Ice  : public AMateria{

	public :

		Ice(std::string const & type);
		Ice(Ice const &copie);
		Ice& operator=(Ice const &copie);
		~Ice();

	protected :

};
