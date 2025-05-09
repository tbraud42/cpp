/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:41:53 by tao               #+#    #+#             */
/*   Updated: 2025/04/29 02:14:43 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include <algorithm>
#include <deque>
#include <vector>
#include <chrono>
#include <iomanip>

class PmergeMe {
	public :
		PmergeMe();
		PmergeMe(PmergeMe const &copie);
		PmergeMe& operator=(PmergeMe const &copie);
		~PmergeMe();

		std::vector<int> vec;
		std::deque<int> deq;
};
