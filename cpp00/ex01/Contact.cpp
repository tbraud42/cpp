/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 23:03:36 by tao               #+#    #+#             */
/*   Updated: 2024/10/04 23:04:28 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string *Contact::GetContact(void) {
	return (this->_info);
}

void	Contact::SetInfo(std::string info[5]) {
	this->_info[0] = info[0];
	this->_info[1] = info[1];
	this->_info[2] = info[2];
	this->_info[3] = info[3];
	this->_info[4] = info[4];
}
