/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:48:31 by tao               #+#    #+#             */
/*   Updated: 2025/04/17 04:37:14 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	parse(*this, "data.csv");
	return ;
}

BitcoinExchange::BitcoinExchange(std::string dataFile) {
	if (!dataFile.empty())
		parse(*this, dataFile);
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
	if (value < 0)
		throw InvalideFormat("not a positive number.");
	bitcoinData.insert(std::pair<std::string, float>(key, value));
	return ;
}

float BitcoinExchange::getClosestDate(const std::string& targetDate) {
	std::map<std::string, float>::const_iterator it = bitcoinData.lower_bound(targetDate);

	if (it != bitcoinData.end() && it->first == targetDate)
		return it->second;

	if (it == bitcoinData.begin())
		throw std::runtime_error("Aucune date disponible avant [" + targetDate + "] "); // a changer

	--it;
	return it->second;
}

