/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:41:53 by tao               #+#    #+#             */
/*   Updated: 2025/04/02 16:03:33 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <limits>

class Span {
	public :
		Span();
		Span(unsigned int N);
		Span(Span const &copie);
		Span& operator=(Span const &copie);
		~Span();

		void addNumber(int toAadd);
		void addRange(int range_begin, int range_end);
		int shortestSpan();
		int longestSpan();

	private :
		std::multiset<int> _containers;
		unsigned int _maxSize;
};
