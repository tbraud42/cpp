/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:48:31 by tao               #+#    #+#             */
/*   Updated: 2025/05/27 19:23:22 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copie) : _vector(copie._vector), _deque(copie._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& copie) {
	if (this != &copie) {
		_vector = copie._vector;
		_deque = copie._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}


bool PmergeMe::parseInput(int ac, char** av) {
	int value;
	int i = 1;

	while (i < ac) {
		std::string arg(av[i]);
		std::istringstream iss(arg);

		if (!(iss >> value)) {
			std::cerr << "Error: Invalid input: " << arg << std::endl;
			return false;
		}
		if (value < 0) {
			std::cerr << "Error: Negative numbers are not allowed: " << arg << std::endl;
			return false;
		}

		_vector.push_back(value);
		_deque.push_back(value);
		++i;
	}
	return true;
}

void PmergeMe::display() const {
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

std::vector<int> PmergeMe::getVector() const {
	return _vector;
}

std::deque<int> PmergeMe::getDeque() const {
	return _deque;
}

void PmergeMe::sortVector() {
	fordJohnsonSortVector(_vector);
}

void PmergeMe::sortDeque() {
	fordJohnsonSortDeque(_deque);
}

template<typename Container>
Container PmergeMe::generateJacobsthalIndices(size_t n) {
	Container indices;
	size_t j1 = 0, j2 = 1;
	while (j2 < n) {
		indices.push_back(j2);
		size_t temp = j2;
		j2 = j2 + 2 * j1;
		j1 = temp;
	}
	return indices;
}


void PmergeMe::fordJohnsonSortVector(std::vector<int>& container) {
	if (container.size() <= 1)
		return;

	std::vector<std::pair<int, int>> pairs;
	auto it = container.begin();
	while (it != container.end()) {
		int first = *it++;
		if (it != container.end()) {
			int second = *it++;
			if (first < second)
				pairs.push_back(std::make_pair(second, first));
			else
				pairs.push_back(std::make_pair(first, second));
		} else {
			pairs.push_back(std::make_pair(first, first));
		}
	}

	std::vector<int> mainChain;
	for (auto& p : pairs)
		mainChain.push_back(p.first);
	fordJohnsonSortVector(mainChain);

	std::vector<int> pend;
	for (auto& p : pairs)
		if (p.first != p.second)
			pend.push_back(p.second);

	std::vector<size_t> jacobsthalIndices = generateJacobsthalIndices<std::vector<size_t>>(pend.size());
	std::vector<bool> inserted(pend.size(), false);

	for (size_t idx : jacobsthalIndices) {
		if (idx < pend.size()) {
			auto pos = std::upper_bound(mainChain.begin(), mainChain.end(), pend[idx]);
			mainChain.insert(pos, pend[idx]);
			inserted[idx] = true;
		}
	}

	for (size_t i = 0; i < pend.size(); ++i) {
		if (!inserted[i]) {
			auto pos = std::upper_bound(mainChain.begin(), mainChain.end(), pend[i]);
			mainChain.insert(pos, pend[i]);
		}
	}

	container.assign(mainChain.begin(), mainChain.end());
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& container) {
	if (container.size() <= 1)
		return;

	std::deque<std::pair<int, int>> pairs;
	auto it = container.begin();
	while (it != container.end()) {
		int first = *it++;
		if (it != container.end()) {
			int second = *it++;
			if (first < second)
				pairs.push_back(std::make_pair(second, first));
			else
				pairs.push_back(std::make_pair(first, second));
		} else {
			pairs.push_back(std::make_pair(first, first));
		}
	}

	std::deque<int> mainChain;
	for (auto& p : pairs)
		mainChain.push_back(p.first);
	fordJohnsonSortDeque(mainChain);

	std::deque<int> pend;
	for (auto& p : pairs)
		if (p.first != p.second)
			pend.push_back(p.second);

	std::deque<size_t> jacobsthalIndices = generateJacobsthalIndices<std::deque<size_t>>(pend.size());
	std::deque<bool> inserted(pend.size(), false);

	for (size_t idx : jacobsthalIndices) {
		if (idx < pend.size()) {
			auto pos = std::upper_bound(mainChain.begin(), mainChain.end(), pend[idx]);
			mainChain.insert(pos, pend[idx]);
			inserted[idx] = true;
		}
	}

	for (size_t i = 0; i < pend.size(); ++i) {
		if (!inserted[i]) {
			auto pos = std::upper_bound(mainChain.begin(), mainChain.end(), pend[i]);
			mainChain.insert(pos, pend[i]);
		}
	}

	container.assign(mainChain.begin(), mainChain.end());
}
