/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:16:20 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 17:30:53 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <random>
#include <time.h>

class RobotomyRequestForm : public AForm {

	public :

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copie);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &copie);
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const ;

	private :

		std::string _target;
};
