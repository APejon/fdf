/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:27:27 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/28 14:12:07 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Retrieves the "target" from the previous function and compares
 * it to the other integers within the list
 * 
 * @param numbers Pointer to a struct that contains the linked list
 * @param target The target integer to compare it to the other integers
 * @param size The size of the DCL to help stop the search
 * @return int 
 */
int	ps_cmp(t_number *numbers, int target, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (numbers->number == target)
			return (-1);
		else
		{
			numbers = numbers->next;
			i++;
		}
	}
	return (0);
}

/**
 * @brief Uses ps_cmp to compare the entire Double Circular Linked (DCL) list 
 * to a single node
 * 
 * @param numbers Double pointer struct containing the numbers
 * @param string String to be free'd if duplicates are found
 * @param size Size of the DCL list
 */
void	ps_cmp_full(t_number **numbers, char *string, int size)
{
	int			i;
	int			flag;
	t_number	*first;

	i = 0;
	flag = 0;
	first = *numbers;
	while (i < size - 1)
	{
		flag = ps_cmp((*numbers)->next, (*numbers)->number, size);
		if (flag == -1)
			ps_free_list(ERR_INPUT, string, numbers, size);
		(*numbers) = (*numbers)->next;
		i++;
	}
	*numbers = first;
}

/*DESCRIPTION

Retrieves the prepared string to check for errors considered by the project's
pdf, splitting the string is considered easier to check on the numbers given
with least amount of mistakes

PARAMETERS

char *string: String given to be checked for errors

NOTES

The 2D-array gained by ft_split is not required outside of the function,
therefore consider freeing immediately
*/
void	ps_check_error(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		while (string[i] <= SPACES && string[i] > '\0')
			i++;
		if (string[i] == '+' || string[i] == '-')
			i++;
		if (!ft_isdigit(string[i]))
			ps_free_string(ERR_INPUT, string);
		while (string[i] >= '0' && string[i++] <= '9')
		{
			if (string[i] <= SPACES || string[i] == '\0')
				break ;
			if (!ft_isdigit(string[i]))
				ps_free_string(ERR_INPUT, string);
		}
	}
}
