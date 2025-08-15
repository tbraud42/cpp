/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/08/15 18:40:32 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

static inline long long getTime() {
	struct timeval tv;
	gettimeofday(&tv, 0);
	return (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;
}

int main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << "Usage: " << av[0] << " <numbers...>" << std::endl;
		return 1;
	}

	PmergeMe merge;

	if (merge.parseInput(ac, av) != 0)
		return 1;

	std::cout << "before :";
	merge.display();
	std::cout << std::endl;

	long long start_vec = getTime();
	merge.sortVector();
	long long end_vec = getTime();

	long long start_deq = getTime();
	merge.sortDeque();
	long long end_deq = getTime();

	std::cout << "after :";
	merge.display();
	std::cout << std::endl;

	long long duration_vec = end_vec - start_vec;
	long long duration_deq = end_deq - start_deq;

	std::cout << "time for vector :"
			  << std::fixed << std::setprecision(5)
			  << static_cast<double>(duration_vec) << " us" << std::endl;

	std::cout << "time for deque :"
			  << std::fixed << std::setprecision(5)
			  << static_cast<double>(duration_deq) << " us" << std::endl;

	return 0;
}
