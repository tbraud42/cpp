/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:16:22 by tao               #+#    #+#             */
/*   Updated: 2025/03/15 17:23:09 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target), AForm ("Shrubbery Form", 25, 5) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copie) : _target(copie._target), AForm ("Shrubbery Form", 25, 5) {
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copie) {
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	return ;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeForExecute() || !this->isSigned())
		throw AForm::GradeTooLowException();

	std::ofstream	shrubbery;
	shrubbery.open((_target + "_shrubbery").c_str(), std::ifstream::out | std::ifstream::trunc);

	if (shrubbery.fail()) { std::cout << "failed to open " << _target + "_shrubbery" << std::endl; return ;}

	shrubbery << "     .{{}}}}}}.     " << std::endl;
	shrubbery << "    {{{{{{(`)}}}.    " << std::endl;
	shrubbery << "   {{{(`)}}}}}}}}}   " << std::endl;
	shrubbery << "  }}}}}}}}}{{(`){{{  " << std::endl;
	shrubbery << "  }}}}{{{{(`)}}{{{{  " << std::endl;
	shrubbery << " {{{(`)}}}}}}}{}}}}} " << std::endl;
	shrubbery << "{{{{{{{{(`)}}}}}}}}}}" << std::endl;
	shrubbery << "{{{{{{{}{{{{(`)}}}}}}" << std::endl;
	shrubbery << " {{{{{(`)   {{{{(`)}'" << std::endl;
	shrubbery << "  `\"\"'\" |   | \"'\"'`" << std::endl;
	shrubbery << "  (`)  /     \\"      << std::endl;
	shrubbery << " ~~~~~~~~~~~~~~~~~~~" << std::endl;

	return ;
}

