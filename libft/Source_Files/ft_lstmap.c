/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:59:56 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:53:00 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates an entire new linked list with its content affected by a 
 * function
 * 
 * @param lst The pointer to a list that will be created
 * @param f The function pointer to affect the content of the node
 * @param del The function pointer to a delete function incase of a mistake
 * @return t_list* The pointer to the first node in the list
 */
t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_node = ft_lstnew(f(lst -> content));
	new_lst = new_node;
	lst = lst -> next;
	while (lst)
	{
		if (!new_node)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_lst, del);
			break ;
		}
		new_node = ft_lstnew(f(lst -> content));
		lst = lst -> next;
		ft_lstadd_back(&new_lst, new_node);
	}
	return (new_lst);
}
