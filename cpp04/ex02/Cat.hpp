/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:16 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:53:40 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{

	public :

		Cat();
		Cat(Cat const &copie);
		Cat& operator=(Cat const &copie);
		~Cat();
		void makeSound() const;
		std::string getIdeas(int i);
		void setIdeas(std::string idea);

	private :

		Brain *brain;
};
