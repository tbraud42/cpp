/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:03:07 by tao               #+#    #+#             */
/*   Updated: 2025/03/21 05:19:04 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

class Base {
	public :
		virtual void f() {}
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
