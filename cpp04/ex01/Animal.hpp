/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:11 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 02:41:32 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal {

	public :

		Animal();
		Animal(std::string name);
		Animal(Animal const &copie);
		Animal& operator=(Animal const &copie);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;

	protected :

		std::string type;

};
