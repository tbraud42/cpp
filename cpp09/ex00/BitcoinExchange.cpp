/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:29:17 by tao               #+#    #+#             */
/*   Updated: 2025/08/16 13:44:13 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <fstream>

static bool parseIntFull(const std::string &s, int &out) {
	if (s.empty()) return false;
	size_t i = 0;
	for (; i < s.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
	}
	std::istringstream iss(s);
	iss >> out;
	return iss && iss.eof();
}

static bool parseFloatFull(const std::string &s, float &out) {
	if (s.empty()) return false;
	char *end = 0;
	const char *c = s.c_str();
	double v = std::strtod(c, &end);
	if (end == c || *end != '\0') return false;
	if (v > std::numeric_limits<float>::max() || v < -std::numeric_limits<float>::max())
		return false;
	out = static_cast<float>(v);
	return true;
}

BitcoinExchange::BitcoinExchange(const std::string &filename) {
	loadDatabase("data.csv");
	processInput(filename);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &file) {
	std::ifstream db(file.c_str());
	std::string line;

	if (!db.is_open()) {
		std::cerr << "Error: could not open data file." << std::endl;
		std::runtime_error("Error: could not open data file.");
		return ;
	}

	std::getline(db, line);
	while (std::getline(db, line)) {
		std::istringstream iss(line);
		std::string date, rateStr;

		if (!std::getline(iss, date, ',')) {
			std::cerr << "Warning: malformed line in database (missing date) => " << line << std::endl;
			continue;
		}

		if (!std::getline(iss, rateStr)) {
			std::cerr << "Warning: malformed line in database (missing rate) => " << line << std::endl;
			continue;
		}

		float rate;
		if (!parseFloatFull(rateStr, rate)) {
			std::cerr << "Warning: invalid rate value in database => " << rateStr << std::endl;
			continue;
		}
		_rates[date] = rate;
	}
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int y, m, d;
	if (!parseIntFull(date.substr(0, 4), y)) return false;
	if (!parseIntFull(date.substr(5, 2), m)) return false;
	if (!parseIntFull(date.substr(8, 2), d)) return false;

	if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
		return false;

	static const int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int maxDays = days[m - 1];
	bool leap = ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) );

	if (m == 2 && leap) maxDays = 29;
	if (d > maxDays) return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value) const {
	if (!parseFloatFull(valueStr, value)) {
		std::cerr << "Error: invalid value => " << valueStr << std::endl;
		return false;
	}
	if (value < 0) {
		std::cerr << "Error: not a positive number -> " << value << std::endl;
		return false;
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number -> " << value << std::endl;
		return false;
	}
	return true;
}

std::string BitcoinExchange::trim(const std::string &str) const {
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

float BitcoinExchange::getRateForDate(const std::string &date) const {
	std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date)
		return it->second;
	if (it == _rates.begin()) {
		std::cerr << "Error: no rate available for date before " << date << std::endl;
		return -1;
	}
	--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string &filename) const {
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open()) {
		std::cerr << "Error: could not open input file." << std::endl;
		std::runtime_error("Error: could not open input file.");
		return ;
	}

	std::getline(file, line);
	while (std::getline(file, line)) {
		if (line.empty())
			continue;

		size_t sep = line.find('|');
		if (sep == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, sep));
		std::string valueStr = trim(line.substr(sep + 1));
		float value;

		if (!isValidDate(date)) {
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue;
		}

		if (!isValidValue(valueStr, value))
			continue;

		float rate = getRateForDate(date);
		if (rate < 0)
			continue;

		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}
