/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:53:51 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/03 18:00:15 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets the values of certain memory addresses to a specific value
 * 
 * @param s The string to be affected
 * @param c The character to change the value into
 * @param n The size of the change
 * @return void* The pointer to the new string affected
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
		ptr[i++] = c;
	return (s);
}
