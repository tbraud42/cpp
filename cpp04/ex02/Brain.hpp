/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:08:30 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:56:04 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"

class Brain {

	public :

		Brain();
		Brain(std::string name);
		Brain(Brain const &copie);
		Brain& operator=(Brain const &copie);
		~Brain();
		std::string getIdeas(int i);
		int setIdeas(std::string idea);

	private :

		std::string ideas[100];

};
