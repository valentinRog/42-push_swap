/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:00:30 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 09:23:21 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(enum e_op op)
{
	if (op == SA)
		put_str_fd("sa\n", STDOUT_FILENO);
	else if (op == SB)
		put_str_fd("sb\n", STDOUT_FILENO);
	else if (op == SS)
		put_str_fd("ss\n", STDOUT_FILENO);
	else if (op == PA)
		put_str_fd("pa\n", STDOUT_FILENO);
	else if (op == PB)
		put_str_fd("pb\n", STDOUT_FILENO);
	else if (op == RA)
		put_str_fd("ra\n", STDOUT_FILENO);
	else if (op == RB)
		put_str_fd("rb\n", STDOUT_FILENO);
	else if (op == RR)
		put_str_fd("rr\n", STDOUT_FILENO);
	else if (op == RRA)
		put_str_fd("rra\n", STDOUT_FILENO);
	else if (op == RRB)
		put_str_fd("rrb\n", STDOUT_FILENO);
	else if (op == RRR)
		put_str_fd("rrr\n", STDOUT_FILENO);
}

void	do_op(enum e_op op, t_ps *ps)
{
	if (op == SA || op == SS)
		swap(&ps->a);
	if (op == SB || op == SS)
		swap(&ps->b);
	if (op == PA)
		push(&ps->b, &ps->a);
	if (op == PB)
		push(&ps->a, &ps->b);
	if (op == RA || op == RR)
		rotate(&ps->a);
	if (op == RB || op == RR)
		rotate(&ps->b);
	if (op == RRA || op == RRR)
		reverse_rotate(&ps->a);
	if (op == RRB || op == RRR)
		reverse_rotate(&ps->b);
	print_op(op);
}
