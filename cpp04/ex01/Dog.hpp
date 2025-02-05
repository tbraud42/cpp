/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:20 by tao               #+#    #+#             */
/*   Updated: 2025/02/05 01:42:48 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal{

	public :

		Dog();
		Dog(Dog const &copie);
		Dog& operator=(Dog const &copie);
		~Dog();
		void makeSound() const;

};
