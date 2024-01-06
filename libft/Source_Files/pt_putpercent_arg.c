/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_putpercent_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:57:43 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:36:22 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_putpercent_arg(char *flags, int lent)
{
	if (!ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, 1);
	write (1, "%", 1);
	if (ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, 1);
	return (1 + lent);
}
