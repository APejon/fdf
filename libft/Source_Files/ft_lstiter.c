/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:34:19 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:51:23 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to every content of a node
 * 
 * @param lst The linked list to be affected
 * @param f The function pointer
 */
void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	t_list	*point;

	if (lst)
	{
		point = lst;
		while (point)
		{
			f(point -> content);
			point = point -> next;
		}
	}
}
