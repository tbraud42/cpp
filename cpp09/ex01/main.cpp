/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/08/29 19:03:43 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool calcul(RPN &rpn, char ope) {
	if (rpn.sizeList() < 2) {
		std::cout << "Error" << std::endl;
		return true;
	}

	int b = rpn.popList();
	int a = rpn.popList();

	if (ope == '+') {
		if ((b > 0 && a > std::numeric_limits<int>::max() - b) ||
			(b < 0 && a < std::numeric_limits<int>::min() - b)) {
			std::cout << "Error" << std::endl;
			return true;
		}
		rpn.pushList(a + b);
	} else if (ope == '-') {
		if ((b < 0 && a > std::numeric_limits<int>::max() + b) ||
			(b > 0 && a < std::numeric_limits<int>::min() + b)) {
			std::cout << "Error" << std::endl;
			return true;
		}
		rpn.pushList(a - b);
	} else if (ope == '*') {
		if (a != 0 && (b > std::numeric_limits<int>::max() / a ||
			b < std::numeric_limits<int>::min() / a)) {
			std::cout << "Error" << std::endl;
			return true;
		}
		rpn.pushList(a * b);
	} else if (ope == '/') {
		if (b == 0) {
			std::cout << "Error" << std::endl;
			return true;
		}
		if (a == std::numeric_limits<int>::min() && b == -1) {
			std::cout << "Error" << std::endl;
			return true;
		}
		rpn.pushList(a / b);
	}

	return false;
}

bool findOperateur(RPN &rpn, char *input) {
	char *ope = strpbrk(input, "+-*/");

	if (calcul(rpn, ope[0])) {return true;}

	ope[0] = ' ';
	return false;
}

void parse(RPN &rpn, char *ope) {
	int i = 0;

	while (ope[i] == ' ') {i++;}
	if (ope[i] >= '0' && ope[i] <= '9') {rpn.pushList(atoi(&ope[i])); i++;}
	else {std::cout << "Error" << std::endl; return ;}

	while (ope[i] == ' ') {i++;}
	if (!ope[i]) {std::cout << rpn.popList() << std::endl; return ;}
	if (ope[i] >= '0' && ope[i] <= '9') {rpn.pushList(atoi(&ope[i])); i++;}
	else {std::cout << "Error" << std::endl; return ;}

	while (ope[i]) {
		while (ope[i] == ' ')
			i++;
		if (ope[i] >= '0' && ope[i] <= '9') {
			rpn.pushList(atoi(&ope[i]));
			ope[i] = ' ';
		} else if (ope[i] == '+' || ope[i] == '-' || ope[i] == '*' || ope[i] == '/') {
			if (findOperateur(rpn, &ope[i]))
				return ;
		} else {std::cout << "Error" << std::endl; return ;}
		i++;
	}
	if (rpn.sizeList() != 1) {std::cout << "Error" << std::endl; return ;}
	std::cout << rpn.popList() << std::endl;
}

int main (int ac, char **av) {
	if (ac == 1) {std::cout << "missing arguments" << std::endl; return 1;}
	if (ac > 2) {std::cout << "too much arguments" << std::endl; return 1;}

	RPN rpn;

	parse(rpn, av[1]);

	return 0;
}
