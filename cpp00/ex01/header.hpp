/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:31:17 by tao               #+#    #+#             */
/*   Updated: 2025/02/02 19:20:22 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring> /* string */
#include <iomanip> /* setw */
#include <cstdlib> /* itoa atoi */
#include "Contact.hpp"
#include "PhoneBook.hpp"

void		ft_print_header(int i);
std::string	ft_resize_string(std::string str);
void		ft_print_search(int i, std::string info[5]);
int			ft_display_search(Contact *contact);
int			ft_find_contact(Contact *contact, int i);
void		ft_contact_empty(void);
