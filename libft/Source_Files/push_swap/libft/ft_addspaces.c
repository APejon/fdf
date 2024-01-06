/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addspaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:51:07 by amalbrei          #+#    #+#             */
/*   Updated: 2022/07/04 17:11:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addspaces(char *flags, int size)
{
	int	lent;
	int	total;

	lent = 0;
	total = ft_atoi(ft_strchr(flags, ft_fn(flags)));
	while (total > size && (ft_strchr(flags, '*') && !ft_strchr(flags, '.')))
	{
		write(1, "0", 1);
		lent++;
		total--;
	}
	while (total > size)
	{
		write(1, " ", 1);
		lent++;
		total--;
	}
	return (lent);
}

void	ft_addtag(char *flags)
{
	if (ft_strchr(flags, 'x'))
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
}
