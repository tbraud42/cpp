/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:03:07 by tao               #+#    #+#             */
/*   Updated: 2025/04/18 15:43:14 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

class Data {

	public :

		Data();
		Data(Data const &copie);
		Data& operator=(Data const &copie);
		~Data();

		std::string tab[2];
		int			i;

};

std::ostream& operator<<(std::ostream& out, const Data& Data);