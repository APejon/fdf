/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_prep_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:35:32 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/28 14:14:55 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the given string is empty or contains only spaces
 * 
 * @param av The 2D array of numbers retrieved from the command line
 * @param sin_str The string containing the entire range of numbers, sent to be 
 * freed in the case of an error
 * @param i The index of the 2D array
 */
void	ps_check_empty_strings(char **av, char *sin_str, int i)
{
	int	j;

	j = 0;
	while (av[i][j] <= SPACES)
	{
		if (av[i][j++] == '\0')
			ps_free_string(ERR_INPUT, sin_str);
	}
}

/*DESCRIPTION

Joins two strings together while subsequently freeing the strings no longer
needed

PARAMETERS

char *s1: First string to join with second string
char *s2: Second string to join with first string
char flag: flag used to identify which part of the joining we free, 
avoiding leaks without losing the strings to join

NOTES
*/
char	*ps_strjoin(char *s1, char *s2, char flag)
{
	char	*combine;

	combine = ft_strjoin(s1, s2);
	if (flag == '1')
		free (s1);
	if (flag == '2')
	{
		free(s1);
		free(s2);
	}
	if (flag == '3')
		free (s2);
	return (combine);
}

/*DESCRIPTION

Prepares the numbers for parsing, this is espicially helpful to deal with given
arguments mixed with double quotes and singular numbers

PARAMETERS

int ac: The number of arguments given by the command line (program name included)
char **av: Arguments of the command line represented as a 2D-array, 
to be used to form a single string
char *char_numbers: The single string that will contain all numbers to be parsed

NOTES

Becareful when joining strings together, it is required to free the first part of
the string as soon the join function ends
*/
char	*ps_prep_numbers(int ac, char **av)
{
	char	*sin_str;
	int		i;

	sin_str = ft_strdup("");
	sin_str = ps_strjoin(sin_str, av[1], '1');
	ps_check_empty_strings(av, sin_str, 1);
	i = 2;
	while (i < ac)
	{
		ps_check_empty_strings(av, sin_str, i);
		sin_str = ps_strjoin(sin_str, " ", '1');
		sin_str = ps_strjoin(sin_str, av[i], '1');
		i++;
	}
	ps_check_error(sin_str);
	return (sin_str);
}
