/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_putchar_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:02:48 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:36:22 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_putchar_arg(va_list args, char *flags, int lent)
{
	char	l;

	l = va_arg(args, int);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, 1);
	write(1, &l, 1);
	lent++;
	if (ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, 1);
	return (lent);
}
