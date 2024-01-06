/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:11:42 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/16 13:22:48 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief swaps first two elements in stack a
 * 
 * @param a stack a represented as a double pointer
 */
void	ps_sa(t_number **a)
{
	int			temp_int;
	int			temp_index;

	temp_int = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = temp_int;
	temp_index = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = temp_index;
	write(1, "sa\n", 3);
}

/**
 * @brief swaps first two elements in stack b
 * 
 * @param b stack b represented as a double pointer
 */
void	ps_sb(t_number **b)
{
	int			temp_int;
	int			temp_index;

	temp_int = (*b)->number;
	(*b)->number = (*b)->next->number;
	(*b)->next->number = temp_int;
	temp_index = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = temp_index;
	write(1, "sb\n", 3);
}

/**
 * @brief uses both sa and sb with one function call
 * 
 * @param a stack a
 * @param b stack b
 */
void	ps_ss(t_number **a, t_number **b)
{
	int			temp_int;
	int			temp_index;

	temp_int = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = temp_int;
	temp_index = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = temp_index;
	temp_int = (*b)->number;
	(*b)->number = (*b)->next->number;
	(*b)->next->number = temp_int;
	temp_index = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = temp_index;
	write(1, "ss\n", 3);
}
