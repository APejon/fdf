/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_puthexa_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:49:41 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:36:53 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_hlenplus(unsigned int c, char *flags, int pr)
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

int	pt_hlent(unsigned int c, char *flags, int pr)
{
	int	len;

	len = 0;
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	len = pt_hlenplus(c, flags, pr);
	while (pr > pt_hlen(c))
	{
		pr--;
		len++;
	}
	return (len);
}

void	pt_puthexax(unsigned int c, int pr, char *flags)
{
	char			*base;
	unsigned char	*a;
	int				i;

	i = 0;
	base = "0123456789ABCDEF";
	if (ft_strchr(flags, 'x'))
		base = "0123456789abcdef";
	while (pr > pt_hlen(c))
	{
		write (1, "0", 1);
		pr--;
	}
	a = ft_calloc(pt_hlen(c), sizeof(char));
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

int	pt_puthexa_arg(va_list args, char *flags, int lent, int pr)
{
	unsigned int	c;

	c = va_arg(args, unsigned int);
	pr = pt_hlen(c);
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	lent = pt_hlent(c, flags, pr);
	if (ft_strchr(flags, '#') && (ft_strchr(flags, '*')) && c != 0)
		pt_addtag(flags);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, lent);
	if (ft_strchr(flags, '#') && !ft_strchr(flags, '*') && c != 0)
		pt_addtag(flags);
	pt_puthexax(c, pr, flags);
	if (ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, lent);
	return (lent);
}
