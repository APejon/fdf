/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_doublequotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:09:09 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/04 19:14:24 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*DESCRIPTION

Checks if the argument contains a double quotes to hold a sentence for certain
commands.

PARAMETERS

char *command: the argument of a command.
*/
int	ft_check_doublequotes(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '"')
		{
			i++;
			if (ft_strchr(command + i, '"'))
				return (1);
		}
		i++;
	}
	return (0);
}
