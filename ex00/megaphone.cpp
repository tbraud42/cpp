/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:30:41 by tbraud            #+#    #+#             */
/*   Updated: 2024/09/09 16:38:06 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int	i;
	
	if (ac == 1)
	{
		std::count << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	i = 0;
	while (av[i] && av[i][0] == '\0')
		i++;
	if (i == ac)
	{
		std::count << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (av[i])
	{
		std::count << av[i];
		i++;
	}
	return 0;
}