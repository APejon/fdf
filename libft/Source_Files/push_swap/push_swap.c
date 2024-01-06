/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:15:22 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/28 14:08:38 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief checks if the list in stack a is already sorted or sorted later
 * 
 * @param numbers double pointer struct pointing to stack a
 * @param size the size of stack a
 */
int	ps_sorted(t_number **numbers, int size)
{
	int			i;
	t_number	*first;

	i = 0;
	first = *numbers;
	while (i < size - 1)
	{
		if ((*numbers)->number < (*numbers)->next->number)
		{
			*numbers = (*numbers)->next;
			i++;
		}
		else
		{
			*numbers = first;
			return (0);
		}
	}
	*numbers = first;
	i = 0;
	return (1);
}

/*DESCRIPTION

Measures the size of the list given by comparing the first node's number with
the subsequent nodes, idea is possible as the project requires us to NOT have
duplicates within our list of numbers

PARAMETERS

t_number **numbers: The double linked list formed within the program

NOTES
*/
int	ps_lstsize(t_number **numbers)
{
	int			first_number;
	int			size;
	t_number	*pointer;

	if (!(*numbers))
		return (0);
	size = 1;
	first_number = (*numbers)->number;
	pointer = (*numbers)->next;
	while (pointer->number != first_number)
	{
		pointer = pointer->next;
		size++;
	}
	return (size);
}

/*Project's PDF: https://cdn.intra.42.fr/pdf/pdf/57819/en.subject.pdf

DESCRIPTION

Arranges numbers presented by the command line in ascending order by 
utilizing two stacks: stack a and stack b, using the minimum (prefereably)
amount of moves using a set number of operations

PARAMETERS

int ac: number of arguments from the command line.
char **av: the strings of arguments received from the command line

NOTES

Steps:
	1-Prepare numbers given as arguments 
	(expect a mix of double quotes and regular numbers)
	
	2-Check for errors incase the numbers given are invalid, errors include:
		+ Non-integer characters
		+ Duplicates
		+ Numbers beyond the "int" limit (aka INT_MIN - 1, INT_MAX = 1)
	
	3-Figure out the size of the Double Linked List formed 
	(since it is not possible to find the end of the list, remedied by the size)

	4-Code the operations stated in the pdf file as functions so that the algorithm 
	changes by only calling said functions (REMEMBER TO CHECK IF ITS ALREADY SORTED)

	5-(CLIMAX) Figure out the algorithm to arrange the numbers, 
	preferably in groups of:
		+ < 100 numbers
		+ >= 100 numbers
		+ = 500 numbers
*/
int	main(int ac, char **av)
{
	int			size;
	char		*char_numbers;
	t_number	*numbers;
	t_number	*b;
	t_min_max	*min_max;

	if (ac == 1)
		return (0);
	b = NULL;
	char_numbers = ps_prep_numbers(ac, av);
	numbers = ps_parse_numbers(char_numbers);
	size = ps_lstsize(&numbers);
	if (!ps_sorted(&numbers, size))
	{
		min_max = malloc(sizeof(t_min_max));
		if (!min_max)
			return (1);
		ps_assign_index(&numbers, size);
		ps_choose_algo(&numbers, &b, min_max, size);
		ps_lstclear(&numbers, size);
		free(min_max);
	}
	else
		ps_lstclear(&numbers, size);
	return (0);
}
