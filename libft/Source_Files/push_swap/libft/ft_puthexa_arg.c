/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:49:41 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/24 19:20:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hlenplus(unsigned int c, char *flags, int pr)
{
	int	len;

	len = 0;
	if (c == 0 && pr != 0)
		len++;
	if (ft_strchr(flags, '#') && c != 0)
		len += 2;
	while (c)
	{
		c = c / 16;
		len++;
	}
	return (len);
}

int	ft_hlent(unsigned int c, char *flags, int pr)
{
	int	len;

	len = 0;
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	len = ft_hlenplus(c, flags, pr);
	while (pr > ft_hlen(c))
	{
		pr--;
		len++;
	}
	return (len);
}

void	ft_puthexax(unsigned int c, int pr, char *flags)
{
	char			*base;
	unsigned char	*a;
	int				i;

	i = 0;
	base = "0123456789ABCDEF";
	if (ft_strchr(flags, 'x'))
		base = "0123456789abcdef";
	while (pr > ft_hlen(c))
	{
		write (1, "0", 1);
		pr--;
	}
	a = ft_calloc(ft_hlen(c), sizeof(char));
	if (c == 0 && pr != 0)
		write(1, "0", 1);
	while (c > 0)
	{
		a[i] = c % 16;
		c = c / 16;
		i++;
	}
	while (i-- > 0)
		write(1, &base[a[i]], 1);
	free(a);
}

int	ft_puthexa_arg(va_list args, char *flags, int lent, int pr)
{
	unsigned int	c;

	c = va_arg(args, unsigned int);
	pr = ft_hlen(c);
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	lent = ft_hlent(c, flags, pr);
	if (ft_strchr(flags, '#') && (ft_strchr(flags, '*')) && c != 0)
		ft_addtag(flags);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, lent);
	if (ft_strchr(flags, '#') && !ft_strchr(flags, '*') && c != 0)
		ft_addtag(flags);
	ft_puthexax(c, pr, flags);
	if (ft_strchr(flags, '-') && ft_strchr(flags, ft_fn(flags)))
		lent += ft_addspaces(flags, lent);
	return (lent);
}
