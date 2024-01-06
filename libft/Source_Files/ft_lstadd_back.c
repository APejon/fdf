/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:03:06 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:49:32 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds to the last node of the list
 * 
 * @param lst The 2D array of a linked list
 * @param new The new node to be added
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*point;

	if (!lst)
		return ;
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			point = ft_lstlast(*lst);
			point -> next = new;
		}
	}
}
