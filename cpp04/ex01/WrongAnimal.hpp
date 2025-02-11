/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:11 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:57:04 by tao              ###   ########.fr       */
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
		virtual ~WrongAnimal();
		std::string getType() const;
		virtual void makeSound() const;

	protected :

		std::string type;

};
