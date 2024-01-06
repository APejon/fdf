/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:57:43 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/16 19:26:56 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpercent_arg(char *flags, int lent)
{
	if (!ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, 1);
	write (1, "%", 1);
	if (ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, 1);
	return (1 + lent);
}
