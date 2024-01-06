/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:27:07 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/24 20:44:08 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
