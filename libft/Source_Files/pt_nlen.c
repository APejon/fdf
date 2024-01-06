/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_nlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:53:58 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:06:46 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pt_printf.h"

int	pt_nlen(int c)
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

unsigned int	pt_unlen(unsigned int c)
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

int	pt_hlen(unsigned int c)
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

int	pt_lhlen(unsigned long int c)
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
