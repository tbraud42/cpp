/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:26:49 by tao               #+#    #+#             */
/*   Updated: 2025/01/10 06:02:29 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>

int main(int ac, char **av)
{
	if (ac != 4) {std::cout << "missing arguments" << std::endl; return (1);}

	std::ifstream file_in;
	file_in.open((std::string(av[1])).c_str(), std::ifstream::in);

	if (file_in.fail()) { std::cout << "failed to open " << av[1] << std::endl; return 1;}


	std::ofstream file_replace;
	file_replace.open((std::string(av[1]) + ".replace").c_str(), std::ifstream::out | std::ifstream::trunc);

	if (file_replace.fail()) { std::cout << "failed to open " << av[1] << ".replace" << std::endl; file_in.close(); return 1;}

	std::string text;
	std::string line;
	while (std::getline(file_in, line))
		text += line + '\n';

	std::size_t i = text.find(av[2]);
	while (i != std::string::npos) {
		text.erase(text.begin() + i, text.begin() + i + strlen(av[2]));
		text.insert(i, av[3]);
		i = text.find(av[2]);
	}

	file_replace << text;

	file_in.close();
	file_replace.close();
	return 0;
}
