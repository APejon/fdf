/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:52:58 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/28 14:32:22 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates stack b to get the largest number back to stack a
 * 
 * @param a Stack a
 * @param b Stack b
 * @param min_max The struct containing the positions of min and max numbers
 * @param size Size of stack b
 */
void	ps_arrange_b(t_number **a, t_number **b, t_min_max **min_max, int size)
{
	while (*b)
	{
		ps_update_min_max(b, min_max, size);
		while ((*b)->index != size && (*min_max)->max <= (size / 2))
			ps_rb(b);
		while ((*b)->index != size && (*min_max)->max >= (size / 2))
			ps_rrb(b);
		ps_pa(a, b);
		size--;
	}
}

/**
 * @brief Searches from for the number within the chunk from the top of 
 * the stack
 * 
 * @param a Stack a
 * @param h_chunk The highest number in the stack
 * @param l_chunk The lowest number in the stack
 * @return int The position of the number found
 */
int	ps_top(t_number **a, int h_chunk, int l_chunk)
{
	t_number	*start;
	int			find;

	start = *a;
	find = 1;
	while (!((*a)->index >= l_chunk && (*a)->index <= h_chunk))
	{
		*a = (*a)->next;
		find++;
	}
	*a = start;
	return (find);
}

/**
 * @brief Searches from for the number within the chunk from the bottom of 
 * the stack
 * 
 * @param a Stack a
 * @param h_chunk The highest number in the stack
 * @param l_chunk The lowest number in the stack
 * @return int The position of the number found
 */
int	ps_bottom(t_number **a, int h_chunk, int l_chunk)
{
	t_number	*start;
	int			find;

	start = *a;
	find = 1;
	while (!((*a)->index >= l_chunk && (*a)->index <= h_chunk))
	{
		*a = (*a)->previous;
		find++;
	}
	*a = start;
	return (find);
}

void	ps_push_bottom(t_number **a, t_number **b, int h_chunk, int l_chunk)
{
	while (ps_bottom(a, h_chunk, l_chunk) != 1)
	{
		if (ps_lstsize(b) >= 2 && (*b)->index < (*b)->previous->index)
			ps_rrr(a, b);
		else
			ps_rra(a);
	}
}

/**
 * @brief Rotates stack a to push the smallest number to b
 * 
 * @param a Stack a
 * @param b Stack b
 * @param h_chunk The highest number of the chunk
 * @param l_chunk The lowest number of the chunk
 */
void	ps_push_to_b(t_number **a, t_number **b, int h_chunk, int l_chunk)
{
	int	sent;

	sent = l_chunk;
	while (sent++ <= h_chunk)
	{
		if (ps_top(a, h_chunk, l_chunk) < ps_bottom(a, h_chunk, l_chunk))
		{
			while (ps_top(a, h_chunk, l_chunk) != 1)
			{
				if (ps_lstsize(b) >= 2 && (*b)->index < (*b)->next->index)
					ps_rr(a, b);
				else
					ps_ra(a);
			}
		}
		else
			ps_push_bottom(a, b, h_chunk, l_chunk);
		ps_pb(a, b);
	}
}
