/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:43:37 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 15:22:37 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

	public :

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &copie);
		Bureaucrat& operator=(Bureaucrat const &copie);
		~Bureaucrat();

		std::string getName() const;
		unsigned int getGrade() const;
		void setGrade(unsigned int grade);
		void upGrade();
		void downGrade();
		void signForm(AForm &form);

		void executeForm(AForm const & form);

	private :

		std::string const _name;
		unsigned int _grade;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
