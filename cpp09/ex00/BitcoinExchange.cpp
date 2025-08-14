// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BitcoinExchange.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: student42                                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/06/18 18:00:00 by student42          #+#    #+#             //
//   Updated: 2025/06/18 18:00:00 by student42         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "BitcoinExchange.hpp"
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>

BitcoinExchange::BitcoinExchange(const std::string &filename) {
	loadDatabase("data.csv");
	processInput(filename);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &file) {
	std::ifstream db(file);
	std::string line;

	if (!db.is_open()) {
		std::cerr << "Error: could not open data file." << std::endl;
		std::exit(EXIT_FAILURE);
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
		try {
			float rate = std::stof(rateStr);
			_rates[date] = rate;
		} catch (const std::exception& e) {
			std::cerr << "Warning: invalid rate value in database => " << rateStr << std::endl;
		}
	}
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int y, m, d;
	try {
		y = std::stoi(date.substr(0, 4));
		m = std::stoi(date.substr(5, 2));
		d = std::stoi(date.substr(8, 2));
	} catch (...) {
		return false;
	}
	if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
		return false;

	static const int daysInMonth[12] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	if (d > daysInMonth[m - 1])
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value) const {
	try {
		size_t idx;
		value = std::stof(valueStr, &idx);
		if (idx != valueStr.length()) {
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
	} catch (const std::exception& e) {
		std::cerr << "Error: invalid value => " << valueStr << std::endl;
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
	std::ifstream file(filename);
	std::string line;
	int lineNumber = 1;

	if (!file.is_open()) {
		std::cerr << "Error: could not open input file." << std::endl;
		return;
	}

	std::getline(file, line);
	while (std::getline(file, line)) {
		++lineNumber;
		if (line.empty())
			continue;

		size_t sep = line.find("|");
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
