/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:40:50 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/24 19:41:55 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_fn(char *flags)
{
	int	i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] >= '1' && flags [i] <= '9')
			return (flags[i]);
		if (flags[i] == '.')
			break ;
		i++;
	}
	return ('\0');
}
