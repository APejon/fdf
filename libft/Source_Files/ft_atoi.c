/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:30:19 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 12:58:26 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Turns a given string into a number with type int
 * 
 * @param str String to be transformed
 * @return int Number after conversion
 */
int	ft_atoi(const char *str)
{
	int		sign;
	size_t	i;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
	}
	if (res > 1844674407370955169 && sign == 1)
		return (-1);
	if (res > 1844674407370955169 && sign == -1)
		return (0);
	return (res * sign);
}
