/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:35:22 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 17:44:18 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Mallocs a certain amount of space to a void pointer and sets it to null
 * 
 * @param count Number of times to iterate the malloc size
 * @param size The size of the count (usually presented as size_of())
 * @return void* Malloced pointer
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size >= SIZE_MAX && count > 1)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}
