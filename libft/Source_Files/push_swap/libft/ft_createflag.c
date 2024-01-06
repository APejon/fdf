/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:43:57 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/23 15:23:59 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_iszero(char p)
{
	if (ft_isdigit(p))
		return (0);
	else if (p == '.')
		return (0);
	else
		return (1);
}

char	*ft_createflag(const char *p, int i)
{
	char	*flags;
	int		j;

	flags = NULL;
	j = i;
	while (ft_isflag(p[j]))
		j++;
	if (ft_isconversion(p[j]))
		j++;
	flags = ft_calloc((j - i) + 1, sizeof(char));
	j = 0;
	while (ft_isflag(p[i]))
	{
		if (p[i] == '0' && (ft_iszero(p[i - 1])))
			flags[j] = '*';
		else
			flags[j] = p[i];
		i++;
		j++;
	}
	flags[j] = p[i];
	return (flags);
}
