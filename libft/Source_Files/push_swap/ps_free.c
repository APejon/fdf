/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:36:21 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/26 12:32:13 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstclear(t_number **node, int size)
{
	int			counter;
	t_number	*temp;

	counter = 0;
	if (node)
	{
		while (counter < size)
		{
			temp = (*node)->next;
			free(*node);
			(*node) = temp;
			counter++;
		}
	}
}

void	ps_free_list(char *err, char *string, t_number **start, int size)
{
	write(2, err, ft_strlen(err));
	free (string);
	ps_lstclear(start, size);
	exit (1);
}

void	ps_free_string(char *err, char *string)
{
	write(2, err, ft_strlen(err));
	free (string);
	exit (1);
}
