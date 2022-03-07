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

void	print_op(int op)
{
	if (op == SA)
		ft_putstr_fd("sa\n", 1);
	else if (op == SB)
		ft_putstr_fd("sb\n", 1);
	else if (op == SS)
		ft_putstr_fd("ss\n", 1);
	else if (op == PA)
		ft_putstr_fd("pa\n", 1);
	else if (op == PB)
		ft_putstr_fd("pb\n", 1);
	else if (op == RA)
		ft_putstr_fd("ra\n", 1);
	else if (op == RB)
		ft_putstr_fd("rb\n", 1);
	else if (op == RR)
		ft_putstr_fd("rr\n", 1);
	else if (op == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (op == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (op == RRR)
		ft_putstr_fd("rrr\n", 1);
}

void	do_op(int op, t_ps *ps)
{
	ps->ops++;
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
	if (ps->print)
		print_op(op);
}
