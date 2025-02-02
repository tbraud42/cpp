/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:57 by tao               #+#    #+#             */
/*   Updated: 2025/02/02 16:23:01 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Fixed::Fixed() : _integer(0) {
// 	std::cout << "Default constructor called" << std::endl;
// 	return ;
// }

// Fixed::Fixed(int const value) {
// 	this->_integer = value;
// 	std::cout << "Int constructor called" << std::endl;
// 	return ;
// }

// Fixed::Fixed(float const value) { // bit shift ?

// 	std::cout << "Float constructor called" << std::endl;
// 	return ;
// }

// Fixed::Fixed(Fixed const & copie) {
// 	*this = copie;
// 	std::cout << "Copy constructor called" << std::endl;
// 	return ;
// }

// Fixed::~Fixed() {
// 	std::cout << "Destructor called" << std::endl;
// 	return ;
// }

// Fixed&	Fixed::operator=(Fixed const & num) { // num en mode float?
// 	std::cout << "Copy assignement operator called" << std::endl;
// 	this->_integer = num.getRawBits();
// 	return *this;
// }


// int Fixed::getRawBits( void ) const {
// 	std::cout << "getRawBits member function called" << std::endl;
// 	return this->_integer;
// }

// void Fixed::setRawBits( int const raw ) {
// 	std::cout << "setRawBits member function called" << std::endl;
// 	this->_integer = raw;
// }


#include "Fixed.hpp"

// Constructeur par défaut
Fixed::Fixed() : _integer(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructeur depuis un entier
Fixed::Fixed(int const value) {
    std::cout << "Int constructor called" << std::endl;
    _integer = value << _int_for_bits; // Décalage de 8 bits vers la gauche
}

// Constructeur depuis un flottant
Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    _integer = roundf(value * (1 << _int_for_bits)); // Conversion en fixed-point
}

// Constructeur de copie
Fixed::Fixed(Fixed const &copie) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copie; // Utilisation de l'opérateur d'assignation
}

// Destructeur
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Opérateur d'assignation
Fixed& Fixed::operator=(Fixed const &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        _integer = fixed.getRawBits();
    return *this;
}

// Accesseur brut
int Fixed::getRawBits(void) const {
    return _integer;
}

// Mutateur brut
void Fixed::setRawBits(int const raw) {
    _integer = raw;
}

// Conversion en float
float Fixed::toFloat(void) const {
    return static_cast<float>(_integer) / (1 << _int_for_bits);
}

// Conversion en int
int Fixed::toInt(void) const {
    return _integer >> _int_for_bits;
}

// Implémentation de l'opérateur <<
std::ostream& operator<<(std::ostream& out, Fixed const &fixed) {
    out << fixed.toFloat(); // Affiche la valeur convertie en float
    return out;
}
