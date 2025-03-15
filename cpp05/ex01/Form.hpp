/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:28:01 by tao               #+#    #+#             */
/*   Updated: 2025/03/14 02:59:22 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public :

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Form();
		Form(std::string name, unsigned int gradeForSign, unsigned int gradeForExecute);
		Form(Form const &copie);
		Form& operator=(Form const &copie);
		~Form();

		std::string getName() const;
		bool isSigned() const;
		void beSigned(Bureaucrat bureaucrat);


	private :

		std::string const _name;
		bool _signed;
		unsigned int const _gradeForSign;
		unsigned int const _gradeForExecute;

};

std::ostream& operator<<(std::ostream& out, const Form& form);
