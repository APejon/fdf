/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_list3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:32:55 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/27 16:51:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_algo_hund(t_number **a, t_number **b, t_min_max *min_max, int size)
{
	int	h_chunk;
	int	l_chunk;
	int	to_send;
	int	size_tmp;

	l_chunk = 1;
	size_tmp = 0;
	to_send = size / 6;
	to_send--;
	h_chunk = to_send;
	while (h_chunk < size)
	{
		ps_push_to_b(a, b, h_chunk, l_chunk);
		l_chunk = h_chunk + 1;
		size_tmp = h_chunk;
		h_chunk += to_send;
	}
	ps_choose_algo(a, b, min_max, size - size_tmp);
	ps_arrange_b(a, b, &min_max, h_chunk - to_send);
}

void	ps_algo_inf(t_number **a, t_number **b, t_min_max *min_max, int size)
{
	int	h_chunk;
	int	l_chunk;
	int	to_send;
	int	size_tmp;

	l_chunk = 1;
	size_tmp = 0;
	to_send = size / 13;
	to_send--;
	h_chunk = to_send;
	while (h_chunk < size)
	{
		ps_push_to_b(a, b, h_chunk, l_chunk);
		l_chunk = h_chunk + 1;
		size_tmp = h_chunk;
		h_chunk += to_send;
	}
	ps_choose_algo(a, b, min_max, size - size_tmp);
	ps_arrange_b(a, b, &min_max, h_chunk - to_send);
}
