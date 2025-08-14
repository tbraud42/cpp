/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:39:01 by tao               #+#    #+#             */
/*   Updated: 2025/06/19 00:26:56 by tao              ###   ########.fr       */
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
		BitcoinExchange(const std::string &filename);
		~BitcoinExchange();

		void processInput(const std::string &filename) const;
};
