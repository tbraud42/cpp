/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:44:22 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 21:05:26 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

	public :

		Intern();
		Intern(Intern const &copie);
		Intern& operator=(Intern const &copie);
		~Intern();


		static AForm *createShrubberyForm(std::string formName);
		static AForm *createRobotomyForm(std::string formName);
		static AForm *createPresidentialForm(std::string formName);
		AForm *makeForm(std::string formName, std::string targetName);
};
