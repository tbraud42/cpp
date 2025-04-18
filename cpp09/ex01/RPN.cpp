/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:48:31 by tao               #+#    #+#             */
/*   Updated: 2025/04/17 05:44:34 by tao              ###   ########.fr       */
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
