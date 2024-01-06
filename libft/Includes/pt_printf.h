/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:32:18 by amalbrei          #+#    #+#             */
/*   Updated: 2022/10/05 13:35:53 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PT_PRINTF_H
# define PT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

int					pt_printf(const char *p, ...);
int					pt_allocate(const char *p, int i, va_list	args, int lent);
int					pt_putchar_arg(va_list args, char *flags, int lent);
int					pt_putstr_arg(va_list args, char *flags, int lent,
						size_t pr);
int					pt_putpointer_arg(va_list args, char *flags, int lent);
int					pt_putnbr_arg(va_list args, char *flags, int len, int pr);
int					pt_uputnbr_arg(va_list args, char *flags, int lent,
						unsigned int pr);
int					pt_puthexa_arg(va_list args, char *flags, int lent, int pr);
int					pt_putpercent_arg(char *flags, int lent);
void				pt_putchars(char c);
int					pt_nlen(int c);
unsigned int		pt_unlen(unsigned int c);
int					pt_hlen(unsigned int c);
int					pt_lhlen(unsigned long int c);
int					pt_isflag(char f);
int					pt_isconversion(char f);
char				*pt_createflag(const char *p, int i);
char				pt_fn(char *flags);
int					pt_addspaces(char *flags, int size);
void				pt_addtag(char *flags);

#endif
