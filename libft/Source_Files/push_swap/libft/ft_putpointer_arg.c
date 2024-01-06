/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:10:07 by amalbrei          #+#    #+#             */
/*   Updated: 2022/06/06 16:44:50 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long int c)
{
	char	*base;
	int		lent;

	lent = 1;
	base = "0123456789abcdef";
	if (c >= 16)
	{
		lent += ft_puthexa(c / 16);
		ft_puthexa(c % 16);
	}
	else
	{
		write(1, &base[c], 1);
	}
	return (lent);
}

int	ft_putpointer_arg(va_list args, char *flags, int lent)
{
	void	*p;

	p = va_arg(args, void *);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, ft_lhlen((unsigned long int) p) + 2);
	write(1, "0x", 2);
	lent += 2;
	lent += ft_puthexa((unsigned long int) p);
	if (ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, ft_lhlen((unsigned long int) p) + 2);
	return (lent);
}
