/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:11 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 16:43:32 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {

	public :

		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal(WrongAnimal const &copie);
		WrongAnimal& operator=(WrongAnimal const &copie);
		~WrongAnimal();
		std::string getType() const;
		void makeSound() const;

	protected :

		std::string type;

};
