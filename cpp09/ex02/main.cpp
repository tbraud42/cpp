/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/08/14 16:21:48 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>
#include <iomanip>

int main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << "Usage: ./" << av[0] << " <numbers...>" << std::endl;
		return 1;
	}

	PmergeMe merge;

	if(merge.parseInput(ac, av) != 0)
		return 1;

	std::cout << "befor :";
	merge.display();
	std::cout << std::endl;

	auto start_vec = std::chrono::high_resolution_clock::now();
	merge.sortVector();
	auto end_vec = std::chrono::high_resolution_clock::now();

	auto start_deq = std::chrono::high_resolution_clock::now();
	merge.sortDeque();
	auto end_deq = std::chrono::high_resolution_clock::now();

	std::cout << "after :";
	merge.display();
	std::cout << std::endl;

	std::chrono::duration<double> duration_vec = end_vec - start_vec;
	std::chrono::duration<double> duration_deq = end_deq - start_deq;

	std::cout	<< "time for vector :"
				<< std::fixed << std::setprecision(5)
				<< duration_vec.count() * 1'000'000 << " us" << std::endl;


	std::cout	<< "time for deque :"
				<< std::fixed << std::setprecision(5)
				<< duration_deq.count() * 1'000'000 << " us" << std::endl;


	return 0;
}
