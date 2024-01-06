/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:33:47 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/21 16:46:48 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_allocate(const char *p, int i, va_list args, int lent)
{
	char	*flags;
	int		pr;

	lent = 0;
	pr = 0;
	flags = NULL;
	flags = ft_createflag(p, i);
	if (ft_strchr(flags, 'c'))
		lent = ft_putchar_arg(args, flags, lent);
	else if (ft_strchr(flags, 's'))
		lent = ft_putstr_arg(args, flags, lent, pr);
	else if (ft_strchr(flags, 'p'))
		lent = ft_putpointer_arg(args, flags, lent);
	else if (ft_strchr(flags, 'd') || ft_strchr(flags, 'i'))
		lent = ft_putnbr_arg(args, flags, lent, pr);
	else if (ft_strchr(flags, 'u'))
		lent = ft_uputnbr_arg(args, flags, lent, pr);
	else if (ft_strchr(flags, 'x') || ft_strchr(flags, 'X'))
		lent = ft_puthexa_arg(args, flags, lent, pr);
	else if (ft_strchr(flags, '%'))
		lent = ft_putpercent_arg(flags, lent);
	free(flags);
	return (lent);
}
