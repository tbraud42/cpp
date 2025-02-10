/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 01:40:17 by tao               #+#    #+#             */
/*   Updated: 2025/02/10 06:55:24 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	public :

		MateriaSource();
		MateriaSource(MateriaSource const &copie);
		MateriaSource& operator=(MateriaSource const &copie);
		~MateriaSource();

		AMateria *getSrc(int i) const;

		void learnMateria(AMateria *);
		AMateria* createMateria(std::string const & type);

	private :

		AMateria	*_src[4];

};

