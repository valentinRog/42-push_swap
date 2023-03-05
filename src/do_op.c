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
	static const char	*op_str[N_OP] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"
	};

	put_str_fd(op_str[op], STDOUT_FILENO);
	put_str_fd("\n", STDOUT_FILENO);
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
