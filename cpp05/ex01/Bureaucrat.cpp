/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:47:06 by tao               #+#    #+#             */
/*   Updated: 2025/03/14 23:48:01 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

Bureaucrat::Bureaucrat() : _name("civil servant"), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade) {
	if (_grade < 1) {
		throw GradeTooHighException();
	}
	if (_grade > 150) {
		throw GradeTooLowException();
	}
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copie) : _name(copie._name), _grade(copie._grade){
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copie) {
	if (this != &copie)
		this->_grade = copie._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	return ;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::setGrade(unsigned int grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
	this->_grade = grade;
}

void Bureaucrat::upGrade() {
	if (this->_grade - 1 < 1) {
		throw GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::downGrade() {
	if (this->_grade + 1 > 150) {
		throw GradeTooLowException();
	}
	this->_grade++;
}

void Bureaucrat::signForm(Form &form) {
	form.beSigned(*this);
	return ;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
