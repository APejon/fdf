/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:52:37 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:50:55 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes a single node and frees it
 * 
 * @param lst The node to be deleted
 * @param del The function pointer of a delete function
 */
void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}
