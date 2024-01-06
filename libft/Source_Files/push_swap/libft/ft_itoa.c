/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:23:31 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/25 16:52:09 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*assign(char *str, size_t i, int n)
{
	size_t	l;

	l = n;
	if (n < 0)
	{
		str[0] = '-';
		l *= -1;
	}
	while (i > 0)
	{
		if (str[i - 1] == '-')
			break ;
		str[i - 1] = (l % 10) + '0';
		l /= 10;
		i--;
	}
	return (str);
}	

static int	counter(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	i = counter(n);
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (str);
	str = assign(str, i, n);
	return (str);
}
