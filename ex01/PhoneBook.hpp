/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:16:13 by tao               #+#    #+#             */
/*   Updated: 2024/10/04 20:29:43 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
// # include <sys/wait.h>
# include <cstring> /* string */
# include <iomanip> /* setw */
# include <stdlib.h> /* itoa */
# include <stdio.h>
# include "Contact.hpp"

class PhoneBook {

public :

	PhoneBook(void);
	~PhoneBook(void);
	void ft_add(void);
	void ft_search(void);

private :

	Contact _info[8]; // mmmmh burger king
	int		_index; //init constructor

};

#endif
