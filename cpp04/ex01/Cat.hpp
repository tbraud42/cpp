/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:12:16 by tao               #+#    #+#             */
/*   Updated: 2025/02/05 01:40:46 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal{

	public :

		Cat();
		Cat(Cat const &copie);
		Cat& operator=(Cat const &copie);
		~Cat();
		void makeSound() const;
};
