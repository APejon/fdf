/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:33:47 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 12:59:53 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_allocate(const char *p, int i, va_list args, int lent)
{
	char	*flags;
	int		pr;

	lent = 0;
	pr = 0;
	flags = NULL;
	flags = pt_createflag(p, i);
	if (ft_strchr(flags, 'c'))
		lent = pt_putchar_arg(args, flags, lent);
	else if (ft_strchr(flags, 's'))
		lent = pt_putstr_arg(args, flags, lent, pr);
	else if (ft_strchr(flags, 'p'))
		lent = pt_putpointer_arg(args, flags, lent);
	else if (ft_strchr(flags, 'd') || ft_strchr(flags, 'i'))
		lent = pt_putnbr_arg(args, flags, lent, pr);
	else if (ft_strchr(flags, 'u'))
		lent = pt_uputnbr_arg(args, flags, lent, pr);
	else if (ft_strchr(flags, 'x') || ft_strchr(flags, 'X'))
		lent = pt_puthexa_arg(args, flags, lent, pr);
	else if (ft_strchr(flags, '%'))
		lent = pt_putpercent_arg(flags, lent);
	free(flags);
	return (lent);
}
