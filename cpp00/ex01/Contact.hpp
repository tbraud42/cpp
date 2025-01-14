/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:30:36 by tbraud            #+#    #+#             */
/*   Updated: 2024/10/04 22:42:31 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {

public :

	Contact(void);
	~Contact(void);
	std::string *GetContact(void);
	void SetInfo(std::string info[5]);

private :

	std::string _info[5]; // first_name, last_name, nikname, phone_number, darkest secret

};

#endif
