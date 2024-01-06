/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_createflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:43:57 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:00:52 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_iszero(char p)
{
	if (ft_isdigit(p))
		return (0);
	else if (p == '.')
		return (0);
	else
		return (1);
}

char	*pt_createflag(const char *p, int i)
{
	char	*flags;
	int		j;

	flags = NULL;
	j = i;
	while (pt_isflag(p[j]))
		j++;
	if (pt_isconversion(p[j]))
		j++;
	flags = ft_calloc((j - i) + 1, sizeof(char));
	j = 0;
	while (pt_isflag(p[i]))
	{
		if (p[i] == '0' && (pt_iszero(p[i - 1])))
			flags[j] = '*';
		else
			flags[j] = p[i];
		i++;
		j++;
	}
	flags[j] = p[i];
	return (flags);
}
