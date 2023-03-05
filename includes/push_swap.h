/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:12:11 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 11:25:45 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	N_OP
};

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list {
	t_node	*head;
	t_node	*tail;
}	t_list;

typedef struct s_ps
{
	t_list	a;
	t_list	b;
}	t_ps;

/*lst*/
t_node			*lst_new(int val);
int				lst_size(t_node *lst);
t_node			*lst_last(t_node *lst);
void			lst_add_front(t_list *lst, t_node *new_node);
void			lst_add_back(t_list *lst, t_node *new_node);

/*op*/
void			swap(t_list *lst);
void			rotate(t_list *lst);
void			reverse_rotate(t_list *lst);
void			push(t_list *src, t_list *dst);

/*do_op*/
void			do_op(enum e_op op, t_ps *ps);

/*cost*/
int				dtt(t_node *node);
t_node			*find_min_cost(t_ps *ps);

/*sort*/
t_node			*homologue(t_node *node_b, t_list a);
bool			is_sorted(t_node *head);
void			sort(t_ps *ps);

/*min_max*/
int				ft_abs(int n);
int				abs_min(int a, int b);
int				abs_max(int a, int b);
t_node			*lst_min(t_node *head);
t_node			*lst_max(t_node *head);

/*chunks*/
void			push_chunks(t_ps *ps);

/*sort_small*/
void			sort_small(t_ps *ps);

/*clear*/
void			ps_clear(t_ps *ps);

/*utils*/
size_t			str_len(const char *str);
void			put_str_fd(const char *s, int fd);
int				str_cmp(char *s1, char *s2);
int				atoi_error(char *str, bool *error);

#endif
