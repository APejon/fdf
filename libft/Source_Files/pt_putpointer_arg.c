/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_putpointer_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:10:07 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:36:22 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_puthexa(unsigned long int c)
{
	char	*base;
	int		lent;

	lent = 1;
	base = "0123456789abcdef";
	if (c >= 16)
	{
		lent += pt_puthexa(c / 16);
		pt_puthexa(c % 16);
	}
	else
	{
		write(1, &base[c], 1);
	}
	return (lent);
}

int	pt_putpointer_arg(va_list args, char *flags, int lent)
{
	void	*p;

	p = va_arg(args, void *);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, pt_lhlen((unsigned long int) p) + 2);
	write(1, "0x", 2);
	lent += 2;
	lent += pt_puthexa((unsigned long int) p);
	if (ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, pt_lhlen((unsigned long int) p) + 2);
	return (lent);
}
