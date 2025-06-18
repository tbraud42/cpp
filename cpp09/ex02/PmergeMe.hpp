/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:41:53 by tao               #+#    #+#             */
/*   Updated: 2025/05/27 19:21:53 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <sstream>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		bool parseInput(int ac, char** av);
		void display() const;

		std::vector<int> getVector() const;
		std::deque<int> getDeque() const;

		void sortVector();
		void sortDeque();

		template<typename Container>
		Container generateJacobsthalIndices(size_t n);

		void fordJohnsonSortVector(std::vector<int>& container);
		void fordJohnsonSortDeque(std::deque<int>& container);

};
