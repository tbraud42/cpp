/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:16:13 by tao               #+#    #+#             */
/*   Updated: 2024/10/03 00:23:00 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <stdlib.h>
# include <sys/wait.h>
# include <cstring>
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
