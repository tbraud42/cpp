/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 01:08:22 by tao               #+#    #+#             */
/*   Updated: 2025/03/20 00:03:14 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copie) {
	*this = copie;
	return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copie) {
	return *this;
}

ScalarConverter::~ScalarConverter() {
	return ;
}


bool is_all_num(char *tab) {
	int i = 0;

	if (tab[i] == '-' || tab[i] == '+')
		i++;

	while (tab[i] && tab[i] >= '0' && tab[i] <= '9')
		i++;

	if (tab[i])
		return false;
	return true;
}

void ScalarConverter::stringToChar(char *input) {
	std::cout << "char : ";

	if (!input[0]) {
		std::cout << "impossible" << std::endl;
		return ;
	}

	if (is_all_num(input)) {
		char *endptr;
		errno = 0;
		long value = std::strtol(input, &endptr, 10);
		if (errno == ERANGE || value < 0 || value > 127) {
			std::cout << "impossible" << std::endl;
		} else if (isprint(static_cast<int>(value))) {
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		} else {
			std::cout << "Non displayable" << std::endl;
		}
	} else if (isprint(static_cast<int>(input[0])) && !input[1]) {
		std::cout << "'" << input[0] << "'" << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::stringToInt(char *input) {
	std::cout << "int : ";

	if (!input[0]) {
		std::cout << "impossible" << std::endl;
		return;
	}

	char *endptr;
	errno = 0;
	long value = std::strtol(input, &endptr, 10);

	if (errno == ERANGE || value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max() || (*endptr != '\0' && *endptr != '.')) {
		std::cout << "impossible" << std::endl;
		return;
	}

	std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::stringToFloat(char *input) {

	std::cout << "float : ";

	if (!input[0]) {
		std::cout << "impossible" << std::endl;
		return;
	}

	char *endptr;
	errno = 0;
	float value = static_cast<float>(std::strtod(input, &endptr));

	if (errno == ERANGE || value < std::numeric_limits<float>::lowest() ||
		value > std::numeric_limits<float>::max() || *endptr != '\0') {
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::stringToDouble(char *input) {

	std::cout << "double : ";

	if (!input[0] ) {
		std::cout << "impossible" << std::endl;
		return;
	}

	char *endptr;
	errno = 0;
	double value = static_cast<double>(std::strtod(input, &endptr));

	if (errno == ERANGE || value < std::numeric_limits<double>::lowest() ||
		value > std::numeric_limits<double>::max() || *endptr != '\0') {
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ScalarConverter &scalarConverter) {
	std::cout << "nothing to display" << std::endl;
	return out;
}
