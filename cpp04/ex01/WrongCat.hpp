/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:16 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:34:42 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal {

	public :

		WrongCat();
		WrongCat(WrongCat const &copie);
		WrongCat& operator=(WrongCat const &copie);
		~WrongCat();
		void makeSound() const;
		std::string getIdeas(int i);
		void setIdeas(std::string idea);

	private :

		Brain *brain;

};
