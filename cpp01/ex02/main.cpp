/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:26:49 by tao               #+#    #+#             */
/*   Updated: 2025/01/04 02:01:02 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {

	std::string mmmh_brain = "HI THIS IS BRAIN";
	std::string *Pmmmh_brain = &mmmh_brain;
	std::string& Refmmmh_brain = mmmh_brain;

	std::cout << "address string: [" << &mmmh_brain << "] pointer: [" << &Pmmmh_brain << "] reference: [" << &Refmmmh_brain << ']' << std::endl;
	std::cout << "string: [" << mmmh_brain << "] pointer: [" << *Pmmmh_brain << "] reference: [" << Refmmmh_brain << ']' << std::endl;
}
