/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:39:51 by kclaudan          #+#    #+#             */
/*   Updated: 2025/11/12 13:39:52 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	i = 1;
	int	j;

	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(av[i][j++])));
		i++;
	}
	return (std::cout << std::endl, 0);
}