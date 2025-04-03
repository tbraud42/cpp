/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:03:07 by tao               #+#    #+#             */
/*   Updated: 2025/03/25 23:50:40 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

template <class T> class Array {

	public:
		Array() : _array(nullptr), _size(0) {}

		Array(unsigned int n) : _array(new T[n]), _size(n) {}

		~Array() {
			delete[] _array;
		}

		Array(const Array& other) : _array(nullptr), _size(other._size) {
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = other._array[i];
			}
		}

		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _array;

				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					_array[i] = other._array[i];
				}
			}
			return *this;
		}

		unsigned int size() const {
			return _size;
		}

		T& operator[](unsigned int index) {
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _array[index];
		}

		const T& operator[](unsigned int index) const {
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _array[index];
		}

	private:
		T* _array;
		unsigned int _size;

};


