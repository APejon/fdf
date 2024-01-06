/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_putnbr_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:56:04 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:36:22 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_nlenplus(int c, char *flags, int pr)
{
	int	len;

	len = 0;
	if (c == 0 && pr != 0)
		len++;
	if (c >= 0 && (ft_strchr(flags, '+') || ft_strchr(flags, ' ')))
		len++;
	while (c)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

int	pt_nlent(int c, char *flags, int pr)
{
	int	len;

	len = 0;
	len = pt_nlenplus(c, flags, pr);
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	while (pr > pt_nlen(c))
	{
		pr--;
		len++;
	}
	if (c < 0)
		len++;
	if (c < 0 && ft_strchr(flags, '*') && !ft_strchr(flags, '.'))
		write(1, "-", 1);
	if (c >= 0 && ft_strchr(flags, '+') && ft_strchr(flags, '*'))
		write(1, "+", 1);
	if (c >= 0 && ft_strchr(flags, ' '))
		write(1, " ", 1);
	return (len);
}

void	pt_putnbr(int nbr, int pr)
{
	char	*a;
	int		i;

	i = 0;
	if (nbr == -2147483648)
	{
		write(1, "2", 1);
		nbr = 147483648;
	}
	if (nbr < 0)
		nbr = nbr * -1;
	a = ft_calloc(pt_nlen(nbr), sizeof(char));
	if (nbr == 0 && pr != 0)
		write(1, "0", 1);
	while (nbr > 0)
	{
		a[i] = (nbr % 10) + '0' ;
		nbr = nbr / 10;
		i++;
	}
	while (i-- > 0)
		write(1, &a[i], 1);
	free(a);
}

int	pt_putnbr_arg(va_list args, char *flags, int lent, int pr)
{
	int	c;

	c = va_arg(args, int);
	pr = pt_nlen(c);
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	lent = pt_nlent(c, flags, pr);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, lent);
	if (c >= 0 && ft_strchr(flags, '+') && !ft_strchr(flags, '*'))
		write(1, "+", 1);
	if (c < 0 && !ft_strchr(flags, '*'))
		write(1, "-", 1);
	if (c < 0 && ft_strchr(flags, '*') && ft_strchr(flags, '.'))
		write(1, "-", 1);
	while (pr > pt_nlen(c))
	{
		write(1, "0", 1);
		pr--;
	}
	pt_putnbr(c, pr);
	if (ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, lent);
	return (lent);
}
