/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:11 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:57:30 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAAnimal {

	public :

		WrongAAnimal();
		WrongAAnimal(std::string name);
		WrongAAnimal(WrongAAnimal const &copie);
		WrongAAnimal& operator=(WrongAAnimal const &copie);
		virutal ~WrongAAnimal() = 0;
		std::string getType() const;
		virutal void makeSound() const = 0;

	protected :

		std::string type;

};
