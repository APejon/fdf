/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:15:30 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 19:09:37 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Find the last occurrence of a character
 * 
 * @param s The string to be searched
 * @param c The character to find
 * @return char* The pointer of the found character in string
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*tar;

	str = (char *) s;
	tar = NULL;
	while (*str)
	{
		if ((unsigned char) *str == (unsigned char) c)
			tar = str;
		str++;
	}
	if (tar == NULL && c != '\0')
		return (NULL);
	if ((unsigned char) *str == (unsigned char) c)
		return (str);
	else
		return (tar);
}
