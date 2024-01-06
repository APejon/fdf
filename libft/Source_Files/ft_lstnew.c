/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:53:03 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:53:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new node
 * 
 * @param content The contents of the node
 * @return t_list* The pointer to the new node
 */
t_list	*ft_lstnew(void	*content)
{
	struct s_list	*new;

	new = malloc(sizeof(struct s_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
