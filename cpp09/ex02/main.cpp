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
    std::vector<T> large;
    std::vector<T> small;

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
void parseInput(Container& container,char **input) {	
	int i = 0;
	while (input[i]) {
		try {
			int val = std::stoi(input[i]);
			if (val < 0)
				throw std::out_of_range();
		} catch (const std::exception &e) {
			std::cout << "invalid argument" << std::endl;
		}
		
		i++;
	}
}

int main() {
    std::vector<int> vec = {32, 11, 48, 7, 29, 15, 51, 19, 43};
    fordJhonsonSort(vec);
    for (int v : vec) std::cout << v << " ";
    std::cout << std::endl;

    std::deque<int> deq = {32, 11, 48, 7, 29, 15, 51, 19, 43};
    fordJhonsonSort(deq);
    for (int v : deq) std::cout << v << " ";
    std::cout << std::endl;


    return 0;
}
