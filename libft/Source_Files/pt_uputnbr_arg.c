/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_uputnbr_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:38:32 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:36:22 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_unlenplus(unsigned int c, int pr)
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

int	pt_unlent(unsigned int c, char *flags, unsigned int pr)
{
	int	len;

	len = 0;
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	len = pt_unlenplus(c, pr);
	while (pr > pt_unlen(c))
	{
		pr--;
		len++;
	}
	return (len);
}

void	pt_uputnbr(unsigned int nbr, int pr)
{
	char	*a;
	int		i;

	i = 0;
	if (nbr == 4294967295)
	{
		write(1, "4", 1);
		nbr = 294967295;
	}
	a = ft_calloc(pt_unlen(nbr), sizeof(char));
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

int	pt_uputnbr_arg(va_list args, char *flags, int lent, unsigned int pr)
{
	unsigned int	c;

	c = va_arg(args, unsigned int);
	pr = pt_unlen(c);
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	lent = pt_unlent(c, flags, pr);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, lent);
	while (pr > pt_unlen(c))
	{
		write(1, "0", 1);
		pr--;
	}
	pt_uputnbr(c, pr);
	if (ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, lent);
	return (lent);
}
