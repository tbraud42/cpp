/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:28:01 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 17:13:29 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public :

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		AForm();
		AForm(std::string name, unsigned int gradeForSign, unsigned int gradeForExecute);
		AForm(AForm const &copie);
		AForm& operator=(AForm const &copie);
		virtual ~AForm();

		std::string getName() const;
		unsigned int getGradeForExecute() const;
		bool isSigned() const;
		void beSigned(Bureaucrat bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;

	private :

		std::string const _name;
		bool _signed;
		unsigned int const _gradeForSign;
		unsigned int const _gradeForExecute;

};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);
