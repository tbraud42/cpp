/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:48:31 by tao               #+#    #+#             */
/*   Updated: 2025/04/22 19:52:33 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	return ;
}

RPN::RPN(RPN const &copie) {
	*this = copie;
	return ;
}

RPN &RPN::operator=(RPN const &copie) {
	return *this;
}

RPN::~RPN() {
	return ;
}

void RPN::pushList(int obj) {
	dataList.push_back(obj);
	return ;
}

int RPN::popList() {
	int value = dataList.back();
	dataList.pop_back();
	return value;
}

int RPN::sizeList() {
	return dataList.size();
}

void RPN::show() {
	std::cout << "Stack : ";
	for (std::list<int>::const_iterator it = dataList.begin(); it != dataList.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
