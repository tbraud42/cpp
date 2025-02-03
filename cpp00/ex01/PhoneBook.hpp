/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:16:13 by tao               #+#    #+#             */
/*   Updated: 2025/02/02 18:36:22 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring> /* string */
#include <iomanip> /* setw */
#include <cstdlib> /* itoa atoi */
#include "Contact.hpp"
#include "header.hpp"

class PhoneBook {

public :

	PhoneBook(void);
	~PhoneBook(void);
	void ft_add(void);
	void ft_search(void);
	Contact *GetPhoneBook(void);

private :

	Contact _info[8];
	int		_index;

};
