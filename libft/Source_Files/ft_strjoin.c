/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:02:15 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 19:04:05 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Joins two strings together into one string
 * 
 * @param s1 First string
 * @param s2 Second string
 * @return char* The complete single string
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
		if (str == NULL)
			return (str);
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			str[i + j] = s2[j];
			j++;
		}
		str[i + j] = '\0';
		return (str);
	}
	return (NULL);
}
