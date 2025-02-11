/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:20 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:54:03 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{

	public :

		Dog();
		Dog(Dog const &copie);
		Dog& operator=(Dog const &copie);
		~Dog();
		void makeSound() const;
		std::string getIdeas(int i);
		void setIdeas(std::string idea);

	private :

		Brain *brain;
};
