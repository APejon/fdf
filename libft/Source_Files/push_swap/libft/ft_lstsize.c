/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:20:35 by amalbrei          #+#    #+#             */
/*   Updated: 2022/08/24 20:57:07 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
