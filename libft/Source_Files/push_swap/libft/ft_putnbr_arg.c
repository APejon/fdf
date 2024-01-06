/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:56:04 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/24 19:15:23 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nlenplus(int c, char *flags, int pr)
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

int	ft_nlent(int c, char *flags, int pr)
{
	int	len;

	len = 0;
	len = ft_nlenplus(c, flags, pr);
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	while (pr > ft_nlen(c))
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

void	ft_putnbr(int nbr, int pr)
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
	a = ft_calloc(ft_nlen(nbr), sizeof(char));
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

int	ft_putnbr_arg(va_list args, char *flags, int lent, int pr)
{
	int	c;

	c = va_arg(args, int);
	pr = ft_nlen(c);
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	lent = ft_nlent(c, flags, pr);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, lent);
	if (c >= 0 && ft_strchr(flags, '+') && !ft_strchr(flags, '*'))
		write(1, "+", 1);
	if (c < 0 && !ft_strchr(flags, '*'))
		write(1, "-", 1);
	if (c < 0 && ft_strchr(flags, '*') && ft_strchr(flags, '.'))
		write(1, "-", 1);
	while (pr > ft_nlen(c))
	{
		write(1, "0", 1);
		pr--;
	}
	ft_putnbr(c, pr);
	if (ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, lent);
	return (lent);
}
