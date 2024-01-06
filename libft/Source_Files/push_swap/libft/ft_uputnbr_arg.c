/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:38:32 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/24 18:37:50 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unlenplus(unsigned int c, int pr)
{
	int	len;

	len = 0;
	if (c == 0 && pr != 0)
		len++;
	while (c)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

int	ft_unlent(unsigned int c, char *flags, unsigned int pr)
{
	int	len;

	len = 0;
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	len = ft_unlenplus(c, pr);
	while (pr > ft_unlen(c))
	{
		pr--;
		len++;
	}
	return (len);
}

void	ft_uputnbr(unsigned int nbr, int pr)
{
	char	*a;
	int		i;

	i = 0;
	if (nbr == 4294967295)
	{
		write(1, "4", 1);
		nbr = 294967295;
	}
	a = ft_calloc(ft_unlen(nbr), sizeof(char));
	if (nbr == 0 && pr != 0)
		write(1, "0", 1);
	while (nbr > 0)
	{
		a[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	while (i-- > 0)
		write(1, &a[i], 1);
	free(a);
}

int	ft_uputnbr_arg(va_list args, char *flags, int lent, unsigned int pr)
{
	unsigned int	c;

	c = va_arg(args, unsigned int);
	pr = ft_unlen(c);
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	lent = ft_unlent(c, flags, pr);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, lent);
	while (pr > ft_unlen(c))
	{
		write(1, "0", 1);
		pr--;
	}
	ft_uputnbr(c, pr);
	if (ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, lent);
	return (lent);
}
