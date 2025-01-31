/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:57 by tao               #+#    #+#             */
/*   Updated: 2025/01/31 02:15:45 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _integer(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const value) {
	this->_integer = value;
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const value) { // bit shift ?

	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & copie) { // dafuck system
	*this = copie; // on fait une fonction d'affectation ?
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const & num) { // num en mode float?
	std::cout << "Copy assignement operator called" << std::endl;
	this->_integer = num.getRawBits();
	return *this;
}


int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_integer;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_integer = raw;
}


