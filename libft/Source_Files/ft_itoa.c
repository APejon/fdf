/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:23:31 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:48:29 by amalbrei         ###   ########.fr       */
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

/**
 * @brief Turns a given number into a string of characters
 * 
 * @param n The number given
 * @return char* The pointer to the string returned 
 * (usually would be pointing to first character)
 */
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
