/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:26:49 by tao               #+#    #+#             */
/*   Updated: 2025/02/03 18:32:43 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {

	std::string mmmh_brain = "HI THIS IS BRAIN";
	std::string *Pmmmh_brain = &mmmh_brain;
	std::string& Refmmmh_brain = mmmh_brain;

	std::cout << "address string: [" << &mmmh_brain << "]" << std::endl;
	std::cout << "pointer: [" << Pmmmh_brain << "]" << std::endl;
	std::cout << "reference: [" << &Refmmmh_brain << ']' << std::endl;

	std::cout << "string: [" << mmmh_brain << ']' << std::endl;
	std::cout << "pointer: [" << *Pmmmh_brain << ']' << std::endl;
	std::cout << "reference: [" << Refmmmh_brain << ']' << std::endl;
}
