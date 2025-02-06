/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:57 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 15:22:44 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _integer(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	_integer = value << _int_for_bits;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	_integer = roundf(value * (1 << _int_for_bits));
}

Fixed::Fixed(Fixed const &copie) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copie;
}

Fixed& Fixed::operator=(Fixed const &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_integer = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return _integer;
}

void Fixed::setRawBits(int const raw) {
	_integer = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_integer) / (1 << _int_for_bits);
}

int Fixed::toInt(void) const {
	return _integer >> _int_for_bits;
}

std::ostream& operator<<(std::ostream& out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
}
