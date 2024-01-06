/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:10:33 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:50:27 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Clears the entire linked list from the program
 * 
 * @param lst The 2D array of a linked list
 * @param del The function pointer to a delete function
 */
void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = temp;
		}
	}
}
