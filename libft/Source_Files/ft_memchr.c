/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:04:08 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:55:42 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds a certain character by memory address
 * 
 * @param s The void pointer to know where to start to look
 * @param c The character to be found represented as an int (ascii table)
 * @param n The size of the search for the character
 * @return void* The pointer to the memory that contains the character
 */
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
