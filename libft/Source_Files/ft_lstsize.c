/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:20:35 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:53:40 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds out the size of the linked list
 * 
 * @param lst The list to be measured
 * @return int The size of the list
 */
int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*point;

	if (!lst)
		return (0);
	count = 0;
	point = lst;
	while (point)
	{
		point = point -> next;
		count++;
	}
	return (count);
}
