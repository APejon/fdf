/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:53:58 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/23 16:10:38 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nlen(int c)
{
	int	len;

	len = 0;
	if (c == 0)
		len++;
	while (c)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

unsigned int	ft_unlen(unsigned int c)
{
	unsigned int	len;

	len = 0;
	if (c == 0)
		len++;
	while (c)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

int	ft_hlen(unsigned int c)
{
	int	len;

	len = 0;
	if (c == 0)
		len++;
	while (c)
	{
		c = c / 16;
		len++;
	}
	return (len);
}

int	ft_lhlen(unsigned long int c)
{
	int	len;

	len = 0;
	if (c == 0)
		len++;
	while (c)
	{
		c = c / 16;
		len++;
	}
	return (len);
}
