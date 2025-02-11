/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:11 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:56:30 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AAnimal {

	public :

		AAnimal();
		AAnimal(std::string name);
		AAnimal(AAnimal const &copie);
		AAnimal& operator=(AAnimal const &copie);
		virtual ~AAnimal() = 0;
		std::string getType() const;
		virtual void makeSound() const = 0;

	protected :

		std::string type;

};
