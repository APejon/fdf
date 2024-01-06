/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:09:55 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/04 19:14:33 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*DESCRIPTION

Returns the error message, this one is a variant case if perror() will not work.

PARAMETERS

char *err: error message given, indicated by pipex.h.

NOTE

Returns 1 as well for the int main, which indicates an error happening during
compilation.
*/
int	ft_error_msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}
