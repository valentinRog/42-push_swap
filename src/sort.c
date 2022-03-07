/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:55:46 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 09:39:03 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*homologue(t_list *node_a, t_list *b)
{
	t_list	*node_b;

	node_b = b;
	if (node_a->val > lst_max(b)->val)
		return (lst_max(b));
	if (node_a->val < lst_min(b)->val)
		return (lst_max(b));
	if (node_a->val < lst_last(b)->val && node_a->val > node_b->val)
		return (node_b);
	node_b = node_b->next;
	while (node_b->next)
	{
		if (node_a->val > node_b->val && node_a->val < node_b->prev->val)
			return (node_b);
		node_b = node_b->next;
	}
	return (node_b);
}

static void	align(t_list *node_a, t_ps *ps)
{
	if (dtt(node_a) > 0 && dtt(homologue(node_a, ps->b)) > 0)
	{
		while (ps->a != node_a && ps->b != homologue(node_a, ps->b))
			do_op(RR, ps);
	}
	else if (dtt(node_a) < 0 && dtt(homologue(node_a, ps->b)) < 0)
	{
		while (ps->a != node_a && ps->b != homologue(node_a, ps->b))
			do_op(RRR, ps);
	}
	if (dtt(node_a) > 0)
		while (ps->a != node_a)
			do_op(RA, ps);
	else
		while (ps->a != node_a)
			do_op(RRA, ps);
	if (dtt(homologue(node_a, ps->b)) > 0)
		while (ps->b != homologue(node_a, ps->b))
			do_op(RB, ps);
	else
		while (ps->b != homologue(node_a, ps->b))
			do_op(RRB, ps);
}

bool	is_sorted(t_list *head)
{
	if (!head)
		return (true);
	if (head->prev)
		if (!(head->val > head->prev->val))
			return (false);
	return (is_sorted(head->next));
}

void	sort(t_ps *ps)
{
	if (is_sorted(ps->a))
		return ;
	if (lst_size(ps->a) <= 5)
		return (sort_small(ps));
	if (ps->prepare)
		prepare(ps);
	while (lst_size(ps->b) < 2)
		do_op(PB, ps);
	while (ps->a)
	{
		align(find_min_cost(ps), ps);
		do_op(PB, ps);
	}
	if (dtt(lst_max(ps->b)) > 0)
		while (ps->b != lst_max(ps->b))
			do_op(RB, ps);
	else
		while (ps->b != lst_max(ps->b))
			do_op(RRB, ps);
	while (ps->b)
		do_op(PA, ps);
}
