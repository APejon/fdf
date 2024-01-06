/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:42:11 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/16 13:18:45 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Adds a new node ontop of an existing node in a stack
 * 
 * @param content the number to be inserted into the new node
 * @param index the index connected to the relative number
 * @param start pointer pointing to the first node of the stack
 */
void	ps_lsttop_push(int content, int index, t_number **start)
{
	t_number	*last;
	t_number	*new;

	new = malloc(sizeof(t_number));
	last = (*start)->previous;
	new->number = content;
	new->index = index;
	new->next = *start;
	new->previous = last;
	last->next = new;
	(*start)->previous = new;
	*start = new;
}

/**
 * @brief Creates a new node incase the stack is empty
 * 
 * @param content the number to be inserted into the new node
 * @param index the index connected to the relative number
 * @return t_number* pointer to the new node created
 */
t_number	*ps_lstnew_push(int content, int index)
{
	t_number	*new;

	new = malloc(sizeof(t_number));
	new->number = content;
	new->index = index;
	new->next = new;
	new->previous = new;
	return (new);
}

/**
 * @brief Deletes the first node of the stack pushed away from to free
 * 
 * @param n the stack that will have its first node deleted
 */
void	ps_del_first_node(t_number **n)
{	
	t_number	*tmp;

	if ((*n) == NULL)
		return ;
	tmp = (*n);
	if (tmp == (*n)->next)
	{
		free((*n));
		(*n) = NULL;
		return ;
	}
	(*n)->next->previous = (*n)->previous;
	(*n)->previous->next = (*n)->next;
	(*n) = (*n)->next;
	free(tmp);
}

/**
 * @brief Function will move from stack b to stack a
 * 
 * @param a stack a
 * @param b stack b
 */
void	ps_pa(t_number **a, t_number **b)
{
	int	tmp;
	int	tmp_i;

	if (!(*b))
		return ;
	tmp = (*b)->number;
	tmp_i = (*b)->index;
	ps_del_first_node(b);
	if (!(*a))
		*a = ps_lstnew_push(tmp, tmp_i);
	else
		ps_lsttop_push(tmp, tmp_i, a);
	write(1, "pa\n", 3);
}

/**
 * @brief Function will move from stack a to stack b
 * 
 * @param a stack a
 * @param b stack b
 */
void	ps_pb(t_number **a, t_number **b)
{
	int	tmp;
	int	tmp_i;

	if (!(*a))
		return ;
	tmp = (*a)->number;
	tmp_i = (*a)->index;
	ps_del_first_node(a);
	if (!(*b))
		*b = ps_lstnew_push(tmp, tmp_i);
	else
		ps_lsttop_push(tmp, tmp_i, b);
	write(1, "pb\n", 3);
}
