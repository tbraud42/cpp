/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:54 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 15:29:01 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <math.h>

class Fixed {

	public :

		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & copie) ;
		Fixed& operator=(Fixed const &num);
		~Fixed(void);

		float toFloat( void ) const;
		int toInt( void ) const;

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		bool operator>(const Fixed &obj);
		bool operator<(const Fixed &obj);
		bool operator>=(const Fixed &obj);
		bool operator<=(const Fixed &obj);
		bool operator==(const Fixed &obj);
		bool operator!=(const Fixed &obj);


		Fixed operator+(const Fixed &obj);
		Fixed operator-(const Fixed &obj);
		Fixed operator/(const Fixed &obj);
		Fixed operator*(const Fixed &obj);

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a,const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a,const Fixed &b);

	private :

		int _integer;
		const static int _int_for_bits = 8;

};

std::ostream& operator<<(std::ostream& out, Fixed const &fixed);
