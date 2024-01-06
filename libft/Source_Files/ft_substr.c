/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:27:07 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 19:13:35 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds a string within a string and mallocs for it
 * 
 * @param s String to be found in the total string
 * @param start Where the substringing starts
 * @param len How far the substringing will go
 * @return char* The character pointer to the newly made string
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*t;
	size_t			i;
	size_t			j;
	size_t			size;

	i = start;
	j = 0;
	size = ft_strlen(s);
	if (!s)
		return (0);
	if (len > size)
		len = size;
	if (start + len > size)
		len = size - start;
	if (start >= size)
		len = 0;
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (0);
	while (i < size && j < len)
		t[j++] = s[i++];
	t[j] = '\0';
	return (t);
}
