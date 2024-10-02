/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:16:13 by tao               #+#    #+#             */
/*   Updated: 2024/10/02 15:18:49 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <stdlib.h>
# include <sys/wait.h>
# include <cstring>

class PhoneBook {

public :

	PhoneBook(void);
	~PhoneBook(void);
	void ft_add(void);
	void ft_search(void);

private :

	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string num;
	std::string secret;
	int			index; //init constructor
};

#endif
