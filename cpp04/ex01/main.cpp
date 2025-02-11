/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:34 by tao               #+#    #+#             */
/*   Updated: 2025/02/11 18:49:01 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	Cat myCat;
	myCat.setIdeas("courgette courgette");
	std::cout << myCat.getIdeas(0) << std::endl;
	std::cout << myCat.getIdeas(1) << std::endl;

	Dog myDog;
	myDog.setIdeas("baguette baguette");
	std::cout << myDog.getIdeas(0) << std::endl;
	std::cout << myDog.getIdeas(1) << std::endl;


	for (int i = 0; i < size; i++)
		delete animals[i];


	return 0;
}
