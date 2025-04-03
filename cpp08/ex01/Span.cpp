/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:48:31 by tao               #+#    #+#             */
/*   Updated: 2025/04/02 16:02:30 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(1) {}

Span::Span(unsigned int N) : _maxSize(N) {
	if (N < 1)
		throw std::out_of_range("Size must be >= 1");
}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_containers = other._containers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int toAdd) {
	if (_containers.size() >= _maxSize)
		throw std::overflow_error("Too many elements in the container");
	_containers.insert(toAdd);
}

void Span::addRange(int range_begin, int range_end) {
	for (int i = range_begin; i <= range_end; ++i) {
		if (_containers.size() >= _maxSize)
			throw std::overflow_error("Too many elements in the container during range insert");
		_containers.insert(i);
	}
}

int Span::shortestSpan() {
	if (_containers.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");

	int minSpan = std::numeric_limits<int>::max();
	for (auto it = std::next(_containers.begin()); it != _containers.end(); ++it) {
		int diff = *it - *std::prev(it);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() {
	if (_containers.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");

	return *_containers.rbegin() - *_containers.begin();
}
