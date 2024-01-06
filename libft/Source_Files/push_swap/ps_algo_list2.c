/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_list2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:23:41 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/28 14:28:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the lowest index available within the stack
 * 
 * @param a Stack a
 * @param size The size of the stack
 * @return int The index found
 */
int	ps_find_lowest_index(t_number **a, int size)
{
	int			i;
	t_number	*target;
	t_number	*start;

	i = 0;
	start = *a;
	target = *a;
	while (i < size)
	{
		*a = (*a)->next;
		if ((*a)->index < target->index)
			target = *a;
		i++;
	}
	*a = start;
	return (target->index);
}

void	ps_algo_four(t_number **a, t_number **b, t_min_max *min_max)
{
	if (min_max->min == 1)
	{
		ps_pb(a, b);
		ps_algo_three(a);
		ps_pa(a, b);
	}
	if (min_max->min == 2)
	{
		if (min_max->max == 1)
			ps_ra(a);
		else
			ps_sa(a);
	}
	if (min_max->min == 3)
	{
		if (min_max->max == 2)
			ps_rra(a);
		else
			ps_ra(a);
	}
	if (min_max->min == 4)
		ps_rra(a);
}

static void	ps_partb(t_number **a, t_min_max *min_max)
{
	if (min_max->min == 3)
	{
		if (min_max->max == 2 && (*a)->index < (*a)->previous->index
			&& (*a)->index < (*a)->previous->previous->index)
			ps_sa(a);
		else
			ps_ra(a);
		if (min_max->max == 2 || min_max->max == 1)
			ps_ra(a);
		else
			ps_sa(a);
	}
	if (min_max->min == 4)
	{
		if (min_max->max == 3)
			ps_ra(a);
		else
			ps_rra(a);
	}
	if (min_max->min == 5)
	{
		ps_rra(a);
	}
}

void	ps_algo_five(t_number **a, t_number **b, t_min_max *min_max, int size)
{
	if (min_max->min == 1)
	{
		ps_pb(a, b);
		size--;
		while (!ps_sorted(a, size))
		{
			ps_update_min_max(a, &min_max, size);
			ps_algo_four(a, b, min_max);
		}
		ps_pa(a, b);
	}
	if (min_max->min == 2)
	{
		if (min_max->max == 1)
			ps_ra(a);
		else
			ps_sa(a);
	}
	ps_partb(a, min_max);
}

void	ps_algo_gtsix(t_number **a, t_number **b, t_min_max *min_max, int size)
{
	int	next_num;
	int	size_temp;

	next_num = ps_find_lowest_index(a, size);
	size_temp = size;
	while (size_temp > 5)
	{
		while ((*a)->index != next_num && min_max->min <= (size / 2))
			ps_ra(a);
		while ((*a)->index != next_num && min_max->min > (size / 2))
			ps_rra(a);
		ps_pb(a, b);
		size_temp--;
		ps_update_min_max(a, &min_max, size_temp);
		next_num++;
	}
	ps_update_min_max(a, &min_max, size_temp);
	ps_choose_algo(a, b, min_max, size_temp);
	while (size_temp++ < size)
		ps_pa(a, b);
}
