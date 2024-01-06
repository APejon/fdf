/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:22:22 by amalbrei          #+#    #+#             */
/*   Updated: 2022/09/28 14:04:45 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* write and read */
# include <unistd.h>

/* malloc, free and exit */
# include <stdlib.h>

/* for libft */
# include "libft/libft.h"

# define SPACES 32
# define ERR_INPUT "Error\n"
# define ERR_MALLOC "Malloc failed\n"

typedef struct s_min_max {
	int		min;
	int		max;
}	t_min_max;

typedef struct s_number {
	struct s_number	*previous;
	int				index;
	int				number;
	struct s_number	*next;
}	t_number;

/* push_swap.c */
int			ps_sorted(t_number **numbers, int size);
int			ps_lstsize(t_number **numbers);

/* ps_prep_numbers.c */
void		ps_check_empty_strings(char **av, char *sin_str, int i);
char		*ps_strjoin(char *s1, char *s2, char flag);
char		*ps_prep_numbers(int ac, char **av);

/* ps_check_error.c */
int			ps_cmp(t_number *numbers, int target, int size);
void		ps_cmp_full(t_number **numbers, char *string, int size);
int			ps_check_number(char *string, int i);
void		ps_check_error(char *string);

/* ps_parse_numbers.c */
t_number	*ps_parse_numbers(char *av);

/* ps_free.c */
void		ps_lstclear(t_number **node, int size);
void		ps_free_list(char *err, char *string, t_number **start, int size);
void		ps_free_string(char *err, char *string);

/* ps_swap.c */
void		ps_sa(t_number **a);
void		ps_sb(t_number **b);
void		ps_ss(t_number **a, t_number **b);

/* ps_push.c */
void		ps_lsttop_push(int content, int index, t_number **start);
t_number	*ps_lstnew_push(int content, int index);
void		ps_del_first_node(t_number **n);
void		ps_pa(t_number **a, t_number **b);
void		ps_pb(t_number **a, t_number **b);

/* ps_rotate.c */
void		ps_ra(t_number **a);
void		ps_rb(t_number **b);
void		ps_rr(t_number **a, t_number **b);

/* ps_rev_rotate.c */
void		ps_rra(t_number **a);
void		ps_rrb(t_number **b);
void		ps_rrr(t_number **a, t_number **b);

/* ps_choose_algo.c */
void		ps_next_largest(t_number **numbers, int size, int count);
void		ps_largest_index(t_number **numbers, int size);
void		ps_assign_index(t_number **numbers, int size);
void		ps_choose_algo(t_number **a, t_number **b, t_min_max *min_max,
				int size);

/* ps_algo_list.c */
int			ps_find_minvalue(t_number **a, int size);
int			ps_find_maxvalue(t_number **numbers, int size);
int			ps_find_position(t_number **a, int min_value);
void		ps_update_min_max(t_number **a, t_min_max **min_max, int size);
void		ps_algo_three(t_number **a);

/* ps_algo_list2.c */
int			ps_find_lowest_index(t_number **a, int size);
void		ps_algo_four(t_number **a, t_number **b, t_min_max *min_max);
void		ps_algo_five(t_number **a, t_number **b, t_min_max *min_max,
				int size);
void		ps_algo_gtsix(t_number **a, t_number **b, t_min_max *min_max,
				int size);

/* ps_algo_list3.c */
void		ps_algo_hund(t_number **a, t_number **b, t_min_max *min_max,
				int size);
void		ps_algo_inf(t_number **a, t_number **b, t_min_max *min_max,
				int size);

/* ps_chunker */
void		ps_arrange_b(t_number **a, t_number **b, t_min_max **min_max,
				int size);
int			ps_top(t_number **a, int h_chunk, int l_chunk);
int			ps_bottom(t_number **a, int h_chunk, int l_chunk);
void		ps_push_to_b(t_number **a, t_number **b, int h_chunk, int l_chunk);

#endif