/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:41:53 by tao               #+#    #+#             */
/*   Updated: 2025/04/17 04:12:06 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>

class InvalideFormat : public std::runtime_error {
	public:
		InvalideFormat(const std::string& message)
			: std::runtime_error(message) {}
};

class BitcoinExchange {
	public :
		BitcoinExchange();
		BitcoinExchange(std::string dataFile);
		BitcoinExchange(BitcoinExchange const &copie);
		BitcoinExchange& operator=(BitcoinExchange const &copie);
		~BitcoinExchange();

		void addStack(std::string key, float value);
		float getClosestDate(const std::string& targetDate);

	private :
		std::map<std::string, float> bitcoinData;
};

void validityDate(std::string date);
void parse(BitcoinExchange stack, std::string dataFile);
