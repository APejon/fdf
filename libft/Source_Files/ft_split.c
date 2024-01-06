/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:48:47 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 18:03:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	assigns(const char *s, char **str, char c, int count)
{
	int	j;
	int	i;
	int	start_index;

	i = 0;
	j = 0;
	while (i < count && s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			start_index = j;
			while (s[j] != c && s[j] != '\0')
				j++;
			str[i] = ft_substr(s, start_index, j - start_index);
			i++;
		}
	}
	str[i] = 0;
}

static int	getwordcount(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			j++;
			i++;
		}
		else if (s[i] != c && s[i + 1] != c)
			i++;
	}
	return (j);
}

/**
 * @brief Splits a string into multiple strings in a 2D array
 * 
 * @param s The string to be split
 * @param c The delimiter to decide how the string is split (usually by space)
 * @return char** The 2D array after splitting
 */
char	**ft_split(const char *s, char c)
{
	size_t		count;
	char		**str;

	if (!s)
		return (NULL);
	count = getwordcount(s, c);
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (str == NULL)
		return (str);
	assigns(s, str, c, count);
	return (str);
}
