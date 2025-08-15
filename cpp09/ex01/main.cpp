/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/08/15 18:31:17 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool calcul(RPN &rpn, char ope) {
	int a;
	int b;

	if (rpn.sizeList() < 2) {std::cout << "Error" << std::endl; return true;}

	if (ope == '+') {
		b = rpn.popList();
		a = rpn.popList();
		rpn.pushList(a + b);
	} else if (ope == '-') {
		b = rpn.popList();
		a = rpn.popList();
		rpn.pushList(a - b);
	} else if (ope == '*') {
		b = rpn.popList();
		a = rpn.popList();
		rpn.pushList(a * b);
	} else {
		b = rpn.popList();
		a = rpn.popList();
		if (b == 0) {std::cout << "cannot divide by '0'" << std::endl; return true;}
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
	if (ac > 2) {std::cout << "to much arguments" << std::endl; return 1;}

	RPN rpn;

	parse(rpn, av[1]);

	return 0;
}
