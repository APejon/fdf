/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_fn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:40:50 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 12:54:12 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

char	pt_fn(char *flags)
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
