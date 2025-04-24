/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:03:07 by tao               #+#    #+#             */
/*   Updated: 2025/03/21 06:09:08 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

template <typename T>
void swap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T min(T x, T y) {
	return (x < y) ? x : y;
}

template <typename T>
T max(T x, T y) {
	return (x > y) ? x : y;
}
