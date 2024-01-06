/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:41:27 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:08:55 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_putprintf(char p)
{
	write(1, &p, 1);
	return (1);
}

int	pt_printf(const char *p, ...)
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
			lent += pt_allocate(p, i, args, lent);
			while (pt_isflag(p[i]))
				i++;
		}
		else
			lent += pt_putprintf(p[i]);
	}
	va_end(args);
	return (lent);
}
