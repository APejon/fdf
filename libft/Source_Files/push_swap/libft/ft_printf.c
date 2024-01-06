/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:41:27 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/24 19:38:57 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putprintf(char p)
{
	write(1, &p, 1);
	return (1);
}

int	ft_printf(const char *p, ...)
{
	va_list	args;
	int		i;
	int		lent;

	va_start(args, p);
	i = -1;
	lent = 0;
	while (p[++i])
	{
		if (p[i] == '%')
		{
			i++;
			if (p[i] == '\0')
				return (i);
			lent += ft_allocate(p, i, args, lent);
			while (ft_isflag(p[i]))
				i++;
		}
		else
			lent += ft_putprintf(p[i]);
	}
	va_end(args);
	return (lent);
}
