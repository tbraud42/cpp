/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:30:36 by tbraud            #+#    #+#             */
/*   Updated: 2025/02/02 21:59:35 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Contact {

public :

	Contact(void);
	~Contact(void);
	std::string *GetContact(void);
	void SetInfo(std::string info[5]);

private :

	std::string _info[5]; // first_name, last_name, nikname, phone_number, darkest secret

};

