/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/04/17 04:39:13 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool leapYearDate(int annee) {
	return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

bool splitDate(const std::string& str, std::string& annee, std::string& mois, std::string& jour) {
	std::size_t pos1 = str.find('-');
	if (pos1 == std::string::npos) return false;

	std::size_t pos2 = str.find('-', pos1 + 1);
	if (pos2 == std::string::npos) return false;

	annee = str.substr(0, pos1);
	mois = str.substr(pos1 + 1, pos2 - pos1 - 1);
	jour = str.substr(pos2 + 1);

	if (annee.empty() || mois.empty() || jour.empty()) return false;

	return true;
}

void validityDate(std::string date) {
	std::string partOfDate[3];

	if (!splitDate(date, partOfDate[0], partOfDate[1], partOfDate[2]))
		throw InvalideFormat("bad input ->             ");

	int years = std::atoi(partOfDate[0].c_str());
	int month = std::atoi(partOfDate[1].c_str());
	int day = std::atoi(partOfDate[2].c_str());

	if (years < 1 || month < 1 || month > 12 || day < 1)
		throw InvalideFormat("bad input ->             ");

	int joursParMois[12] = { 31, 28, 31, 30, 31, 30,
							 31, 31, 30, 31, 30, 31 };

	if (month == 2 && leapYearDate(years)) {
		if (day > 29)
			throw InvalideFormat("bad input ->             ");
	}
	else {
		if (day > joursParMois[month - 1])
			throw InvalideFormat("bad input ->             ");
	}
}

char	checkFormat(std::string line) {
	if (line == "date,exchange_rate") {
		return (',');
	} else if (line == "date | value") {
		return ('|');
	} else {
		std::cout << "the format description is incorrect" << std::endl;
		return (0);
	}
}

void isValidFloat(const std::string& str, bool isForDataBase) {
	std::istringstream iss(str);
	float f;
	char c;

	if (!(iss >> f))
		throw InvalideFormat("float overflow ->        ");

	if (iss >> c)
		throw InvalideFormat("invalid value ->         ");

	if (!isForDataBase) {
		if (f < 0)
			throw InvalideFormat("not a positive number -> ");
		if (f > 1000)
			throw InvalideFormat("too large a number    -> ");
	}


}

void	parse(BitcoinExchange stack, std::string dataFile) {
	std::ifstream file_in;
	file_in.open(dataFile, std::ifstream::in);
	if (file_in.fail()) {
		std::cout << "failed to open " << dataFile << std::endl;
		return ;
	}

	std::string line;
	std::getline(file_in, line);
	char delimiter = checkFormat(line);
	if (delimiter == 0)
		return ;

	while (std::getline(file_in, line)) {
		try {
			std::size_t pos = line.find(delimiter);
			std::string date;
			std::string value;
			if (pos != std::string::npos && pos != 0 && pos != line.length() - 1) { // a verifier
				date = line.substr(0, pos);
				value = line.substr(pos + 1);
				validityDate(date);
			} else
				throw InvalideFormat("bad input ->             ");
			isValidFloat(value, true);
			std::cout << date << "|" << value << std::endl;
			stack.addStack(date, static_cast<float>(std::atof(value.c_str())));
		} catch (std::exception &e) {
			std::cerr << dataFile << " Error : " << e.what() << line << std::endl;
		}
	}

	file_in.close();
	return ;
}



int main (int ac, char **av) {
	if (ac == 1) {std::cout << "missing arguments" << std::endl; return 1;}
	if (ac > 2) {std::cout << "to much arguments" << std::endl; return 1;}

	BitcoinExchange data;

	std::ifstream file_in;
	file_in.open(std::string(av[1]).c_str(), std::ifstream::in);
	if (file_in.fail()) { std::cout << "failed to open " << std::string(av[1]).c_str() << std::endl; return 1;}

	std::string line;
	std::getline(file_in, line);
	char delimiter = checkFormat(line);
	if (delimiter == 0) {return 1;}

	while (std::getline(file_in, line)) {
		try {
			std::size_t pos = line.find(delimiter);
			std::string date;
			std::string value;
			if (pos != std::string::npos && pos != 0 && pos != line.length() - 1) {
				date = line.substr(0, pos - 1);
				value = line.substr(pos + 1);
				validityDate(date);
			} else
				throw InvalideFormat("bad input ->             ");
			std::cout << date << "|" << value << std::endl;
			isValidFloat(value, false);
			float btcRate = data.getClosestDate(date);
			float result = btcRate * std::atof(value.c_str());
			std::cout << date << " => " << value << " = " << result << std::endl;
		} catch (std::exception &e) {
			std::cerr << av[1] << " Error : " << e.what() << line << std::endl;
		}
	}


	return 0;
}
