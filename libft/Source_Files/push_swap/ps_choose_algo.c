/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_choose_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:12:37 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/27 14:56:13 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the next largest number to index
 * 
 * @param numbers The 2D struct that contains the nodes
 * @param size The 2D struct that contains the nodes
 * @param count The index to assign to the number
 */
void	ps_next_largest(t_number **numbers, int size, int count)
{
	int			i;
	int			largest;
	t_number	*largest_p;

	i = 0;
	while ((*numbers)->index)
		*numbers = (*numbers)->next;
	largest = (*numbers)->number;
	largest_p = *numbers;
	while (++i < size)
	{
		*numbers = (*numbers)->next;
		if ((*numbers)->number > largest)
		{
			if ((*numbers)->index != 0)
				continue ;
			else
			{
				largest = (*numbers)->number;
				largest_p = *numbers;
			}
		}
	}
	*numbers = largest_p;
	(*numbers)->index = count;
}

/**
 * @brief Finds the largest number and indexes it
 * 
 * @param numbers The 2D struct that contains the nodes
 * @param size Size of the 2D struct
 */
void	ps_largest_index(t_number **numbers, int size)
{
	int			i;
	int			largest;
	t_number	*largest_p;

	i = 0;
	largest = (*numbers)->number;
	largest_p = *numbers;
	while (i < size)
	{
		*numbers = (*numbers)->next;
		if ((*numbers)->number > largest)
		{
			largest = (*numbers)->number;
			largest_p = *numbers;
		}
		i++;
	}
	largest_p->index = size;
	*numbers = largest_p;
}

/**
 * @brief Assigns indexes to the nodes of a stack
 * 
 * @param numbers The 2D struct that contains the nodes
 * @param size Size of the 2D struct
 */
void	ps_assign_index(t_number **numbers, int size)
{
	int			i;
	int			count;
	t_number	*start;

	i = 1;
	start = *numbers;
	ps_largest_index(numbers, size);
	count = size - 1;
	while (i < size)
	{
		ps_next_largest(numbers, size, count);
		i++;
		count--;
	}
	*numbers = start;
}

/**
 * @brief Chooses algorithm depending on the size of the linked list
 * 
 * @param a Stack a
 * @param b Stack b
 * @param min_max The struct containing the positons of the min and max numbers
 * @param size Size of the linked list
 */
void	ps_choose_algo(t_number **a, t_number **b, t_min_max *min_max, int size)
{
	while (!ps_sorted(a, size))
	{
		ps_update_min_max(a, &min_max, size);
		if (size == 2)
			ps_sa(a);
		if (size == 3)
			ps_algo_three(a);
		if (size == 4)
			ps_algo_four(a, b, min_max);
		if (size == 5)
			ps_algo_five(a, b, min_max, size);
		if (size >= 6 && size < 100)
			ps_algo_gtsix(a, b, min_max, size);
		if (size >= 100 && size < 500)
			ps_algo_hund(a, b, min_max, size);
		if (size >= 500)
			ps_algo_inf(a, b, min_max, size);
	}
}
