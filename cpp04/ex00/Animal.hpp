/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:11 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 23:33:07 by tao              ###   ########.fr       */
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
		~Animal();
		std::string getType();

	protected :

		std::string type;

};
