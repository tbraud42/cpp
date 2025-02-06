/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:20 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:30:05 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{

	public :

		Dog();
		Dog(Dog const &copie);
		Dog& operator=(Dog const &copie);
		~Dog();
		void makeSound() const;

	private :

		Brain *brain;
};
