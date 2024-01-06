/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:50:41 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/16 19:26:10 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char f)
{
	if (f == '-' || f == '+' || f == ' ' || f == '#' || f == '0' || f == '.'
		|| f == '*' || ft_isdigit(f))
		return (1);
	else
		return (0);
}

int	ft_isconversion(char f)
{
	if (f == 'c' || f == 's' || f == 'p' || f == 'd' || f == 'i' || f == 'u'
		|| f == 'x' || f == 'X' || f == '%')
		return (1);
	else
		return (0);
}
