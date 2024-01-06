/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:12:52 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:11:32 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Puts a character in a specific file
 * 
 * @param c Character to be printed
 * @param fd File descriptor
 */
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
