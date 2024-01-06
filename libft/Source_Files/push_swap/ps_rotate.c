/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:06:35 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/16 13:16:14 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief rotates stack a UPWARDS (first element becomes last)
 * 
 * @param a stack a
 */
void	ps_ra(t_number **a)
{
	*a = (*a)->next;
	write (1, "ra\n", 3);
}

/**
 * @brief rotates stack b UPWARDS (first element becomes last)
 * 
 * @param b stack b
 */
void	ps_rb(t_number **b)
{
	*b = (*b)->next;
	write (1, "rb\n", 3);
}

/**
 * @brief rotates the lists UPWARDS (first element becomes last)
 * 
 * @param a stack a
 * @param b stack b
 */
void	ps_rr(t_number **a, t_number **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	write(1, "rr\n", 3);
}
