/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_putstr_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:07:02 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:36:22 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_printnull(char *flags)
{
	int		lent;
	int		pr;
	int		i;
	char	*n;

	lent = 0;
	pr = 6;
	i = 0;
	n = "(null)";
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	if (pr > 6)
		pr = 6;
	if (!ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, 6 + (pr - 6));
	while (i < pr)
	{
		write(1, &n[i++], 1);
		lent++;
	}
	if (ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, 6 + (pr - 6));
	return (lent);
}

int	pt_printstr(char *w, size_t pr)
{
	size_t	i;

	i = 0;
	while (w[i] && i < pr)
	{
		write(1, &w[i], 1);
		i++;
	}
	return (i);
}

int	pt_putstr_arg(va_list args, char *flags, int lent, size_t pr)
{
	char	*w;

	w = va_arg(args, char *);
	pr = ft_strlen(w);
	if (w == NULL)
		lent += pt_printnull(flags);
	if (w == NULL)
		return (lent);
	if (ft_strchr(flags, '.'))
		pr = ft_atoi(ft_strchr(flags, '.') + 1);
	if (pr > ft_strlen(w))
		pr = ft_strlen(w);
	if (!ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, ft_strlen(w) + (pr - ft_strlen(w)));
	lent += pt_printstr(w, pr);
	if (ft_strchr(flags, '-') && ft_strchr(flags, pt_fn(flags)))
		lent += pt_addspaces(flags, ft_strlen(w) + (pr - ft_strlen(w)));
	return (lent);
}
