/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:32:18 by amalbrei          #+#    #+#             */
/*   Updated: 2022/06/06 16:33:49 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

int					ft_printf(const char *p, ...);
int					ft_allocate(const char *p, int i, va_list	args, int lent);
int					ft_putchar_arg(va_list args, char *flags, int lent);
int					ft_putstr_arg(va_list args, char *flags, int lent,
						size_t pr);
int					ft_putpointer_arg(va_list args, char *flags, int lent);
int					ft_putnbr_arg(va_list args, char *flags, int len, int pr);
int					ft_uputnbr_arg(va_list args, char *flags, int lent,
						unsigned int pr);
int					ft_puthexa_arg(va_list args, char *flags, int lent, int pr);
int					ft_putpercent_arg(char *flags, int lent);
void				ft_putchars(char c);

int					ft_nlen(int c);
unsigned int		ft_unlen(unsigned int c);
int					ft_hlen(unsigned int c);
int					ft_lhlen(unsigned long int c);
int					ft_isflag(char f);
int					ft_isconversion(char f);
char				*ft_createflag(const char *p, int i);
char				ft_fn(char *flags);
int					ft_addspaces(char *flags, int size);
void				ft_addtag(char *flags);

#endif
