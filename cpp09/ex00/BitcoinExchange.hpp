/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:39:01 by tao               #+#    #+#             */
/*   Updated: 2025/08/24 21:45:39 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <fstream>
#include <iostream>

class InvalideFormat : public std::runtime_error {
	public:
		InvalideFormat(const std::string& message)
			: std::runtime_error(message) {}
};

class BitcoinExchange {
	private:
		std::map<std::string, float> _rates;

		void loadDatabase(const std::string &file);
		bool isValidDate(const std::string &date) const;
		bool isValidValue(const std::string &valueStr, float &value) const;
		std::string trim(const std::string &str) const;
		float getRateForDate(const std::string &date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void processInput(const std::string &filename) const;
};
