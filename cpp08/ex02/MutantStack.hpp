/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:41:53 by tao               #+#    #+#             */
/*   Updated: 2025/04/03 13:37:36 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdexcept>
#include <stack>

template <class T> class MutantStack : public std::stack<T> {
	public :
		MutantStack() {};
		MutantStack(MutantStack const &copie) {this = *copie;};
		MutantStack& operator=(MutantStack const &copie) {
			std::stack<T>::operator=(copie);
			return *this;
		}
		~MutantStack() {};

		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack<T>::iterator begin() {
			return this->c.begin();
		}

		MutantStack<T>::iterator end() {
			return this->c.end();
		}
	private :

};
