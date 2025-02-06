/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:54 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 15:22:30 by tao              ###   ########.fr       */
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

	private :

		int _integer;
		const static int _int_for_bits = 8;

};

std::ostream& operator<<(std::ostream& out, Fixed const &fixed);
