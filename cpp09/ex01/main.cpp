/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/04/17 05:46:03 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool calcul(RPN &rpn, char ope) {
	int a;
	int b;

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

void parse(RPN &rpn, char *ope) {
	int i = 0;

	while (ope[i]) {
		while (ope[i] == ' ')
			i++;
		if (ope[i] >= '0' && ope[i] <= '9') {
			rpn.pushList(atoi(&ope[i]));
			if (rpn.sizeList() == 3) {std::cout << "missing operateur" << std::endl; return ;}
		} else if (ope[i] == '+' || ope[i] == '-' || ope[i] == '*' || ope[i] == '/') {
			if (calcul(rpn, ope[i]))
				return ;
		} else {std::cout << "unrecognized character '" << ope[i] << "'" << std::endl; return ;}
	}
}

int main (int ac, char **av) {
	if (ac == 1) {std::cout << "missing arguments" << std::endl; return 1;}
	if (ac > 2) {std::cout << "to much arguments" << std::endl; return 1;}

	RPN rpn;

	parse(rpn, av[1]);

	// parser pour que a b + c * d +
	// push(a) push(b) calcul(+) push(result) push(c) calcul(*) push(result) ....
	return 0;
}
