/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:58:05 by tao               #+#    #+#             */
/*   Updated: 2025/03/24 00:00:23 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// std::cout << max<int>(3, 7) << std::endl;
	// std::cout << min<double>(3.0, 7.0) << std::endl;
	// std::cout << max<char>('g', 'e') << std::endl;

	// char tmp_one = 'a';
	// char tmp_two = 'b';

	// swap<char>(tmp_one, tmp_two);
	// std::cout << tmp_one << ' ' << tmp_two << std::endl;

	// int a = 69;
	// int b = 71;

	// swap<int>(a, b);
	// std::cout << a << ' ' << b << std::endl;

	return 0;
}
