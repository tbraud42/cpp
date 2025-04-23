/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:33:06 by tao               #+#    #+#             */
/*   Updated: 2025/04/18 15:52:53 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cerrno>
#include <limits>

class ScalarConverter {

	public :
		static void convert(std::string input);
	
	private :
		ScalarConverter();
		ScalarConverter(ScalarConverter const &copie);
		ScalarConverter& operator=(ScalarConverter const &copie);
		~ScalarConverter();

};

std::ostream& operator<<(std::ostream& out, const ScalarConverter& scalarConverter);

void stringToChar(std::string input);
void stringToInt(std::string input);
void stringToFloat(std::string input);
void stringToDouble(std::string input);