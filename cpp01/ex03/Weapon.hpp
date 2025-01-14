/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:12:55 by tao               #+#    #+#             */
/*   Updated: 2025/01/06 09:35:57 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <new>

class Weapon {

	public :

		Weapon();
		Weapon(std::string weapon);
		~Weapon(void);

		const std::string& getType(void);
		void setType(std::string weapon);

	private :

		std::string _type;

};

