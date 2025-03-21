/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:33:06 by tao               #+#    #+#             */
/*   Updated: 2025/03/19 20:56:25 by tao              ###   ########.fr       */
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

		ScalarConverter();
		ScalarConverter(ScalarConverter const &copie);
		ScalarConverter& operator=(ScalarConverter const &copie);
		~ScalarConverter();

		void stringToChar(char *input);
		void stringToInt(char *input);
		void stringToFloat(char *input);
		void stringToDouble(char *input);

	private :

};

std::ostream& operator<<(std::ostream& out, const ScalarConverter& scalarConverter);
