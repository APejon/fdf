/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:12:38 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/16 13:16:28 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief rotates stack a DOWNWARDS (last element becomes first)
 * 
 * @param a stack a
 */
void	ps_rra(t_number **a)
{
	*a = (*a)->previous;
	write (1, "rra\n", 4);
}

/**
 * @brief rotates stack b DOWNWARDS (last element becomes first)
 * 
 * @param b stack b
 */
void	ps_rrb(t_number **b)
{
	*b = (*b)->previous;
	write (1, "rrb\n", 4);
}

/**
 * @brief rotates the lists DOWNWARDS (last element becomes first)
 * 
 * @param a stack a
 * @param b stack b
 */
void	ps_rrr(t_number **a, t_number **b)
{
	*a = (*a)->previous;
	*b = (*b)->previous;
	write(1, "rrr\n", 4);
}
