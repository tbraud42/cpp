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

	rpn.show();
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
	rpn.show();
	return false;
}

bool findOperateur(RPN &rpn, char *input) {
	int i = 0;
	char *ope = strpbrk(input, "+-*/");

	if (!ope) {std::cout << "Error missing operateur" << std::endl; return true;}
	
	if (calcul(rpn, ope[0])) {std::cout << "Error cannot divide by '0'" << std::endl; return true;}

	ope[0] = ' ';
	return false;
}

void parse(RPN &rpn, char *ope) {	 
	int i = 0;

	while (ope[i] == ' ') {i++;}
	if (ope[i] >= '0' && ope[i] <= '9') {rpn.pushList(atoi(&ope[i]));} 
	else {std::cout << "Error" << std::endl; return ;}

	while (ope[i] == ' ') {i++;}
	if (ope[i] >= '0' && ope[i] <= '9') {rpn.pushList(atoi(&ope[i]));} 
	else {std::cout << "Error" << std::endl; return ;}

	while (ope[i]) {
		while (ope[i] == ' ')
			i++;
		if (rpn.sizeList() == 2) {
			if (findOperateur(rpn, &ope[i]))
				return ;
			else
				continue ;
		} else if (ope[i] >= '0' && ope[i] <= '9') {
			std::cout << i << std::endl;
			rpn.pushList(atoi(&ope[i]));
			rpn.show();
		} else {std::cout << "Error" << std::endl; return ;}
		i++;
	}
	std::cout << rpn.popList() << std::endl;
}

int main (int ac, char **av) {
	if (ac == 1) {std::cout << "missing arguments" << std::endl; return 1;}
	if (ac > 2) {std::cout << "to much arguments" << std::endl; return 1;}

	RPN rpn;

	parse(rpn, av[1]);

	return 0;
}
