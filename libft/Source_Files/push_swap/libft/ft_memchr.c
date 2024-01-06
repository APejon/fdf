/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:04:08 by amalbrei          #+#    #+#             */
/*   Updated: 2022/01/29 15:40:25 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned char		target;

	i = 0;
	str = (unsigned char *) s;
	target = (unsigned char) c;
	while (i < n)
	{
		if (*str == target)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
