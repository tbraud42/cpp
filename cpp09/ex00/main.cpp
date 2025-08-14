/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:38:31 by tao               #+#    #+#             */
/*   Updated: 2025/06/18 20:39:15 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << "Fatal error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
