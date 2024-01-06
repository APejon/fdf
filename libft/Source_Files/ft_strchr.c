/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:38 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 18:04:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the first occurence of a character within a string
 * 
 * @param s The string to be checked
 * @param c The character to be found
 * @return char* The pointer to the found character within the string
 */
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *) s;
	while ((unsigned char ) *str != (unsigned char) c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
