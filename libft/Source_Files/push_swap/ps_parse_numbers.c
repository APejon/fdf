/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:39:31 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/12 13:39:45 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_atoi(const char *str, int size, char *av, t_number **start)
{
	int		sign;
	size_t	i;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
	}
	if (res > 2147483647 && sign == 1)
		ps_free_list(ERR_INPUT, av, start, size);
	if (res > 2147483648 && sign == -1)
		ps_free_list(ERR_INPUT, av, start, size);
	return (res * sign);
}

static void	ps_next_number(t_number **start, int content, int size)
{
	t_number	*last;
	t_number	*new;

	last = (*start)->previous;
	new = malloc(sizeof(t_number));
	if (!new)
		ps_lstclear(start, size);
	new->number = content;
	new->index = 0;
	new->next = *start;
	(*start)->previous = new;
	new->previous = last;
	last->next = new;
}

static t_number	*ps_lstnew(int content, char *av)
{
	t_number	*new;

	new = malloc(sizeof(t_number));
	if (!new)
		ps_free_string(ERR_MALLOC, av);
	new->number = content;
	new->index = 0;
	new->next = new;
	new->previous = new;
	return (new);
}

/**
 * @brief extracts the numbers from the obtained string and atois it
 * to newly created nodes
 * 
 * @param av string extracted from the comand line
 * @return t_number* pointer to nodes created
 */
t_number	*ps_parse_numbers(char *av)
{
	int			i;
	int			size;
	t_number	*start;

	i = 0;
	size = 0;
	while (av[i] <= SPACES)
		i++;
	start = ps_lstnew(ps_atoi(&av[i], size, av, NULL), av);
	size++;
	while ((av[i] >= '0' && av[i] <= '9') || av[i] == '+' || av[i] == '-')
		i++;
	while (av[i])
	{
		while (av[i] <= SPACES)
			i++;
		ps_next_number(&start, ps_atoi(&av[i], size, av, &start), size);
		size++;
		while ((av[i] >= '0' && av[i] <= '9') || av[i] == '+' || av[i] == '-')
			i++;
	}
	ps_cmp_full(&start, av, size);
	free (av);
	return (start);
}
