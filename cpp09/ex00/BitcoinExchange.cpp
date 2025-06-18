/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:48:31 by tao               #+#    #+#             */
/*   Updated: 2025/06/18 20:21:51 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	parse(this, "data.csv");
	return ;
}

BitcoinExchange::BitcoinExchange(std::string dataFile) {
	if (!dataFile.empty())
		parse(this, dataFile);
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copie) {
	*this = copie;
	return ;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &num) {
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	return ;
}

void BitcoinExchange::addStack(std::string key, float value) {
	bitcoinData.insert(std::pair<std::string, float>(key, value));
	return ;
}

float BitcoinExchange::getClosestDate(const std::string& targetDate) {
	std::map<std::string, float>::const_iterator it = bitcoinData.lower_bound(targetDate);

	if (it != bitcoinData.end() && it->first == targetDate)
		return it->second;

	if (it == bitcoinData.begin())
		throw std::runtime_error("no earlier date known -> " + targetDate);

	--it;
	return it->second;
}

void BitcoinExchange::show() {
	for (std::map<std::string, float>::const_iterator it = bitcoinData.begin(); it != bitcoinData.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
}
