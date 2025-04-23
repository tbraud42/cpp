/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:03:07 by tao               #+#    #+#             */
/*   Updated: 2025/04/18 15:40:58 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

class Base {
	public :
		virtual ~Base() {}
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};

Base * generate(void);
void identify(Base* p);

std::ostream& operator<<(std::ostream& out, const Base& Base);
