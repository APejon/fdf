/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:43:44 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 19:05:11 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates two strings together while returning the result
 * 
 * @param dst The string destination to concatenate on
 * @param src The string source to concatenate with
 * @param dstsize The size of the destination
 * @return size_t The size of the string concatenated
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	len_d;
	size_t	len_s;

	j = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (dstsize <= len_d)
		len_s = dstsize + len_s;
	else
	{
		len_s = len_s + len_d;
		while (len_d < (dstsize - 1) && src[j])
		{
			dst[len_d] = src[j];
			j++;
			len_d++;
		}
		dst[len_d] = '\0';
	}
	return (len_s);
}
