/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:48:32 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/27 14:08:19 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
