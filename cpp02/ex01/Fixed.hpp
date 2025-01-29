/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:54 by tao               #+#    #+#             */
/*   Updated: 2025/01/29 15:58:37 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {

	public :

		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & copie) ; // constructeur par recopie ?
		~Fixed(void);

		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed& operator=(Fixed const &num);// operateur pour quoi faire
		int getRawBits( void ) const;
		void setRawBits( int const raw );


	private :

		int _integer;
		const static int _int_for_bits = 8;

};
