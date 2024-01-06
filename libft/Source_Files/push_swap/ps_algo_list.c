/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:53:12 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/28 14:27:41 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the minimum value within a certain stack
 * 
 * @param numbers Stack a or b
 * @param size The size of the stack
 * @return int The minimum number in the stack
 */
int	ps_find_minvalue(t_number **numbers, int size)
{
	int			i;
	int			min_num;
	t_number	*start;

	i = 0;
	min_num = (*numbers)->number;
	start = *numbers;
	while (i < size)
	{
		(*numbers) = (*numbers)->next;
		if ((*numbers)->number < min_num)
			min_num = (*numbers)->number;
		i++;
	}
	*numbers = start;
	return (min_num);
}

/**
 * @brief Finds the maximum value within a certain stack
 * 
 * @param numbers Stack a or b
 * @param size The size of the stack
 * @return int The maximum number in the stack
 */
int	ps_find_maxvalue(t_number **numbers, int size)
{
	int			i;
	int			max_num;
	t_number	*start;

	i = 0;
	max_num = (*numbers)->number;
	start = *numbers;
	while (i < size)
	{
		(*numbers) = (*numbers)->next;
		if ((*numbers)->number > max_num)
			max_num = (*numbers)->number;
		i++;
	}
	*numbers = start;
	return (max_num);
}

/**
 * @brief Finds the position of the number given to the function
 * 
 * @param numbers Either stack a or b
 * @param value The number retrieved to find its position
 * @return int The position of the number
 */
int	ps_find_position(t_number **numbers, int value)
{
	int			pos;
	t_number	*start;

	pos = 1;
	start = *numbers;
	while ((*numbers)->number != value)
	{
		*numbers = (*numbers)->next;
		pos++;
	}
	*numbers = start;
	return (pos);
}

/**
 * @brief Assigns and updates the positions of the minimum and maximum numbers 
 * within a certain stack
 * 
 * 
 * @param a Stack a or stack b in some cases
 * @param min_max The struct containing the min and max numbers' positions
 * @param size The size of the stack
 */
void	ps_update_min_max(t_number **a, t_min_max **min_max, int size)
{
	int	num;

	num = ps_find_minvalue(a, size);
	(*min_max)->min = ps_find_position(a, num);
	num = ps_find_maxvalue(a, size);
	(*min_max)->max = ps_find_position(a, num);
}

/**
 * @brief Arranges a stack size of 3
 * 
 * @param a Stack a
 */
void	ps_algo_three(t_number **a)
{
	if ((*a)->index > (*a)->next->index)
	{
		if ((*a)->next->index < (*a)->previous->index && (*a)->index
			< (*a)->previous->index)
			ps_sa(a);
		else if ((*a)->next->index > (*a)->previous->index)
		{
			ps_sa(a);
			ps_rra(a);
		}
		else if ((*a)->next->index < (*a)->previous->index && (*a)->index
			> (*a)->previous->index)
			ps_ra(a);
	}
	else if ((*a)->index < (*a)->next->index)
	{
		if ((*a)->previous->index > (*a)->index)
		{
			ps_sa(a);
			ps_ra(a);
		}
		else if ((*a)->previous->index < (*a)->index)
			ps_rra(a);
	}
}
