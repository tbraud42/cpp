/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/04/03 13:34:54 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<size_t> jacobsthal(size_t n) {
	std::vector<size_t> indices;
	size_t j0 = 0, j1 = 1;
	while (j1 <= n) {
		indices.push_back(j1);
		size_t next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	std::vector<bool> used(n + 1, false);
	std::vector<size_t> result;
	for (size_t j : indices) {
		if (j <= n && !used[j]) {
			result.push_back(j);
			used[j] = true;
		}
	}
	for (size_t i = 1; i <= n; ++i) {
		if (!used[i]) {
			result.push_back(i);
		}
	}
	return result;
}

template <typename Container>
void fordJhonsonSort(Container& container) {
	if (container.size() <= 1) return;

	using T = typename Container::value_type;
	Container large;
	Container small;

	size_t i = 0;
	while (i + 1 < container.size()) {
		if (container[i] < container[i + 1]) {
			small.push_back(container[i]);
			large.push_back(container[i + 1]);
		} else {
			small.push_back(container[i + 1]);
			large.push_back(container[i]);
		}
		i += 2;
	}
	T last;
	bool has_odd = false;
	if (i < container.size()) {
		last = container[i];
		has_odd = true;
	}

	std::sort(large.begin(), large.end());

	std::vector<size_t> order = jacobsthal(small.size());
	for (size_t idx : order) {
		if (idx == 0 || idx > small.size()) continue;
		auto pos = std::lower_bound(large.begin(), large.end(), small[idx - 1]);
		large.insert(pos, small[idx - 1]);
	}

	if (has_odd) {
		auto pos = std::lower_bound(large.begin(), large.end(), last);
		large.insert(pos, last);
	}

	container.assign(large.begin(), large.end());
}

template <typename Container>
bool parseInput(Container& container, char **input) {
	int i = 0;
	while (input[i]) {
		try {
			int val = std::stoi(input[i]);
			if (val < 0)
				throw std::out_of_range("Negative value not allowed");
			container.push_back(val);
		} catch (const std::exception &e) {
			std::cout << "invalid argument" << std::endl;
			return false;
		}
		i++;
	}
	return true;
}

int main(int argc, char** argv) {
	PmergeMe container;
	
	auto start_vec = std::chrono::high_resolution_clock::now();
	if (parseInput(container.vec, argv + 1)) {
		fordJhonsonSort(container.vec);
		for (int v : container.vec) std::cout << v << " ";
	}
	auto end_vec = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_vec = end_vec - start_vec;
	std::cout << "\nTime (vector): " << duration_vec.count() << "s" << std::endl;

	auto start_deq = std::chrono::high_resolution_clock::now();
	if (parseInput(container.deq, argv + 1)) {
		fordJhonsonSort(container.deq);
		for (int v : container.deq) std::cout << v << " ";
	}
	auto end_deq = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_deq = end_deq - start_deq;
	std::cout << "\nTime (deque): " << duration_deq.count() << "s" << std::endl;

	return 0;
}
