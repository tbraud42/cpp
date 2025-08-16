/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:41:53 by tao               #+#    #+#             */
/*   Updated: 2025/08/16 13:40:39 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <algorithm>
#include <list>

class RPN {
	public :
		RPN();
		RPN(RPN const &copie);
		RPN& operator=(RPN const &copie);
		~RPN();

		void pushList(int obj);
		int popList();
		int sizeList();
		void show();

	private :
		std::list<int>dataList;
};
