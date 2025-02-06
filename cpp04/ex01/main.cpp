/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:25:34 by tao               #+#    #+#             */
/*   Updated: 2025/02/06 03:13:57 by tao              ###   ########.fr       */
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

	for (int i = 0; i < size; i++)
		delete animals[i];

	return 0;
}
