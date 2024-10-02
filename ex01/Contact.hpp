/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:30:36 by tbraud            #+#    #+#             */
/*   Updated: 2024/10/02 22:18:48 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {

public :

	Contact(void);
	~Contact(void);
	void SetInfo(std::string info[5]);

private :

	std::string _info[5];
	
};

#endif