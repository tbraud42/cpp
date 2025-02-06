/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:34 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:31:01 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// AAnimal bob("bob");
	const int size = 4;
	AAnimal* Animals[size];

	for (int i = 0; i < size / 2; i++)
		Animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		Animals[i] = new Cat();


	for (int i = 0; i < size; i++)
		delete Animals[i];


	return 0;
}
