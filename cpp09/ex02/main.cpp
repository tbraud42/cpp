/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:40:38 by tao               #+#    #+#             */
/*   Updated: 2025/04/29 03:04:50 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end) {
	for (Iterator i = begin + 1; i < end; ++i) {
		auto key = *i;
		Iterator j = i;
		while (j > begin && *(j - 1) > key) {
			*j = *(j - 1);
			--j;
		}
		*j = key;
	}
}


template <typename Container>
Container generateJacobsthal(const Container&, size_t n) {
	Container sequence;
	size_t j0 = 0, j1 = 1;
	while (j1 <= n) {
		sequence.push_back(j1);
		size_t next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}

	Container used(n + 1, false);
	Container order;
	for (size_t j : sequence) {
		if (j <= n && !used[j]) {
			order.push_back(j);
			used[j] = true;
		}
	}
	for (size_t i = 1; i <= n; ++i) {
		if (!used[i]) {
			order.push_back(i);
		}
	}
	return order;
}

template <typename Container>
void mergePhase(Container& container, size_t groupSize) {
	using T = typename Container::value_type;
	if (groupSize >= container.size()) return;

	Container containerOfGroups;

	for (size_t i = 0; i < container.size(); i += groupSize) {
		size_t end = std::min(i + groupSize, container.size());

		Container group;
		for (size_t j = i; j < end; ++j) { group.push_back(container[j]);}
		insertionSort(group.begin(), group.end());
		containerOfGroups.push_back(group);
	}

	for (auto it1 = containerOfGroups.begin(); it1 != containerOfGroups.end(); ++it1) {
		for (auto it2 = std::next(it1); it2 != containerOfGroups.end(); ++it2) {
			if (it1->back() > it2->back()) {
				std::swap(*it1, *it2);
			}
		}
	}

	container.clear();
	for (auto& group : containerOfGroups) {
		container.insert(container.end(), group.begin(), group.end());
	}

	mergePhase(container, groupSize * 2);
}

template <typename Container>
void splitMainPend(const Container& container, Container& main, Container& pend) {
	size_t mid = container.size() / 2;
	main.insert(main.end(), container.begin(), container.begin() + mid);
	pend.insert(pend.end(), container.begin() + mid, container.end());
}

template <typename Container>
void insertionPhase(Container& main, Container& pend) {
	if (pend.empty()) return;

	auto order = generateJacobsthal(pend, pend.size());

	for (size_t idx : order) {
		if (idx == 0 || idx > pend.size()) continue;
		auto pos = std::lower_bound(main.begin(), main.end(), pend[idx - 1]);
		main.insert(pos, pend[idx - 1]);
	}
}

template <typename Container>
void fordJohnsonSort(Container& container) {
	if (container.size() <= 1) return;

	mergePhase(container, 1);

	Container main, pend;
	splitMainPend(container, main, pend);
	insertionPhase(main, pend);

	container = main;
}

template <typename Container>
bool parseInput(Container& container, char** argv) {
	int i = 0;
	while (argv[i]) {
		try {
			int val = std::stoi(argv[i]);
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

	if (!parseInput(container.vec, argv + 1)) return 1;
	if (!parseInput(container.deq, argv + 1)) return 1;

	for (int v : container.vec) std::cout << v << " ";
	std::cout << std::endl;

	auto start_vec = std::chrono::high_resolution_clock::now();
	fordJohnsonSort(container.vec);
	auto end_vec = std::chrono::high_resolution_clock::now();

	auto start_deq = std::chrono::high_resolution_clock::now();
	fordJohnsonSort(container.deq);
	auto end_deq = std::chrono::high_resolution_clock::now();

	for (int v : container.vec) std::cout << v << " ";
	std::cout << std::endl;

	std::chrono::duration<double> duration_vec = end_vec - start_vec;
	std::chrono::duration<double> duration_deq = end_deq - start_deq;

	std::cout << "Time to process a range of " << container.vec.size()
			  << " elements with std::vector : "
			  << std::fixed << std::setprecision(5)
			  << duration_vec.count() * 1'000'000 << " us" << std::endl;

	std::cout << "Time to process a range of " << container.deq.size()
			  << " elements with std::deque : "
			  << std::fixed << std::setprecision(5)
			  << duration_deq.count() * 1'000'000 << " us" << std::endl;

	return 0;
}
