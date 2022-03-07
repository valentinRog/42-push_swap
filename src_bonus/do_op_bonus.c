/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:33:19 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 11:33:21 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	do_op_str(char *op, t_ps *ps)
{
	if (!ft_strcmp(op, "sa"))
		do_op(SA, ps);
	else if (!ft_strcmp(op, "sb"))
		do_op(SB, ps);
	else if (!ft_strcmp(op, "ss"))
		do_op(SS, ps);
	else if (!ft_strcmp(op, "pa"))
		do_op(PA, ps);
	else if (!ft_strcmp(op, "pb"))
		do_op(PB, ps);
	else if (!ft_strcmp(op, "ra"))
		do_op(RA, ps);
	else if (!ft_strcmp(op, "rb"))
		do_op(RB, ps);
	else if (!ft_strcmp(op, "rr"))
		do_op(RR, ps);
	else if (!ft_strcmp(op, "rra"))
		do_op(RRA, ps);
	else if (!ft_strcmp(op, "rrb"))
		do_op(RRB, ps);
	else if (!ft_strcmp(op, "rrr"))
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
