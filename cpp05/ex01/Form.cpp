/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:26:25 by tao               #+#    #+#             */
/*   Updated: 2025/03/14 03:18:55 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

Form::Form() : _name("tax form"), _signed(false), _gradeForSign(150), _gradeForExecute(150) {
	return ;
}

Form::Form(std::string name, unsigned int gradeForSign, unsigned int gradeForExecute) : _name(name), _signed(false), _gradeForSign(gradeForSign), _gradeForExecute(gradeForExecute) {
	if (gradeForSign > 150)
		throw Form::GradeTooLowException();
	if (gradeForSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeForExecute > 150)
		throw Form::GradeTooLowException();
	if (_gradeForExecute < 1)
		throw Form::GradeTooHighException();
	return ;
}

Form::Form(Form const &copie) : _name(copie._name), _signed(copie._signed), _gradeForSign(copie._gradeForSign), _gradeForExecute(copie._gradeForExecute) {
	return ;
}

Form &Form::operator=(Form const &copie) {
	this->_signed = copie._signed;
	return *this;
}

Form::~Form() {
	return ;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::isSigned() const {
	return this->_signed;
}

void Form::beSigned(Bureaucrat bureaucrat) {
	if (this->_signed) {
		std::cout <<  bureaucrat.getName() << " couldn’t sign " << this->_name << " because is already signed." << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > this->_gradeForSign){
		std::cout <<  bureaucrat.getName() << " couldn’t sign " << this->_name << " because his grade is too low." << std::endl;
		return ;
	}
	this->_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
	if (form.isSigned())
		std::cout << form.getName() << ", is sign." << std::endl;
	else
		std::cout << form.getName() << ", is not sign." << std::endl;
	return out;
}
