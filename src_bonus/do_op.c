/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:25:00 by vrogiste          #+#    #+#             */
/*   Updated: 2022/05/26 11:25:00 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	do_op_str(char *op, t_ps *ps)
{
	if (!str_cmp(op, "sa\n"))
		do_op(SA, ps);
	else if (!str_cmp(op, "sb\n"))
		do_op(SB, ps);
	else if (!str_cmp(op, "ss\n"))
		do_op(SS, ps);
	else if (!str_cmp(op, "pa\n"))
		do_op(PA, ps);
	else if (!str_cmp(op, "pb\n"))
		do_op(PB, ps);
	else if (!str_cmp(op, "ra\n"))
		do_op(RA, ps);
	else if (!str_cmp(op, "rb\n"))
		do_op(RB, ps);
	else if (!str_cmp(op, "rr\n"))
		do_op(RR, ps);
	else if (!str_cmp(op, "rra\n"))
		do_op(RRA, ps);
	else if (!str_cmp(op, "rrb\n"))
		do_op(RRB, ps);
	else if (!str_cmp(op, "rrr\n"))
		do_op(RRR, ps);
	else
		return (-1);
	return (0);
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
}
