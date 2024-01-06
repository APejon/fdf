/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:16:51 by amalbrei          #+#    #+#             */
/*   Updated: 2022/01/26 13:26:11 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	i = 0;
	if (!dest && !src)
		return (0);
	if (csrc < cdest)
		while (++i <= n)
			cdest[n - i] = csrc[n - i];
	else
	{
		while (n-- > 0)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}
