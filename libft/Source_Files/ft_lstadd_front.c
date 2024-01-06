/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:20:07 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:50:00 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new node to the beginning of the list
 * 
 * @param lst The 2D array of a linked list
 * @param new The new node to be added
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new -> next = (*lst);
	*lst = new;
}
