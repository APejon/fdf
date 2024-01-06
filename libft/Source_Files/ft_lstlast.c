/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:48:32 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:51:44 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the last node in the list
 * 
 * @param lst The linked list to be checked
 * @return t_list* The pointer to the last node of the list
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*point;

	if (!lst)
		return (NULL);
	point = lst;
	while (point)
	{
		if (point -> next == NULL)
			return (point);
		point = point -> next;
	}
	return (NULL);
}
