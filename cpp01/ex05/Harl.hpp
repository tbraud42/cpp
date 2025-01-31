/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 06:08:02 by tao               #+#    #+#             */
/*   Updated: 2025/01/31 23:36:35 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

class Harl {

	public :
		Harl();
		~Harl();
		void complain( std::string level );


	private :

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

};
