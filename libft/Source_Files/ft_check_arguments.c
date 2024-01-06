/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:53:18 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/04 19:15:04 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the arguments are allowed to be used by the program
 * 
 * @param ac Number of arguments
 * @param av The arguments as 2D strings declared from the command line
 */
void	ft_check_arguments(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 5)
		exit (1);
	while (av[2][i] == ' ')
		i++;
	if (av[2][i] == '\0')
		exit (1);
	i = 0;
	while (av[3][i] == ' ')
		i++;
	if (av[3][i] == '\0')
		exit (1);
	return ;
}
