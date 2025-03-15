/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:26:25 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 17:13:20 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

AForm::AForm() : _name("tax Form"), _signed(false), _gradeForSign(150), _gradeForExecute(150) {
	return ;
}

AForm::AForm(std::string name, unsigned int gradeForSign, unsigned int gradeForExecute) : _name(name), _signed(false), _gradeForSign(gradeForSign), _gradeForExecute(gradeForExecute) {
	if (gradeForSign > 150)
		throw AForm::GradeTooLowException();
	if (gradeForSign < 1)
		throw AForm::GradeTooHighException();
	if (_gradeForExecute > 150)
		throw AForm::GradeTooLowException();
	if (_gradeForExecute < 1)
		throw AForm::GradeTooHighException();
	return ;
}

AForm::AForm(AForm const &copie) : _name(copie._name), _signed(copie._signed), _gradeForSign(copie._gradeForSign), _gradeForExecute(copie._gradeForExecute) {
	return ;
}

AForm &AForm::operator=(AForm const &copie) {
	this->_signed = copie._signed;
	return *this;
}

AForm::~AForm() {
	return ;
}

std::string AForm::getName() const {
	return this->_name;
}

unsigned int AForm::getGradeForExecute() const {
	return this->_gradeForExecute;
}

bool AForm::isSigned() const {
	return this->_signed;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->_gradeForExecute)
		throw AForm::GradeTooLowException();
	std::cout << this->_name << " has been executed" << std::endl;
}

void AForm::beSigned(Bureaucrat bureaucrat) {
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

std::ostream &operator<<(std::ostream &out, AForm const &AForm) {
	if (AForm.isSigned())
		std::cout << AForm.getName() << ", is sign." << std::endl;
	else
		std::cout << AForm.getName() << ", is not sign." << std::endl;
	return out;
}
