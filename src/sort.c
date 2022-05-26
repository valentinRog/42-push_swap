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

t_list	*homologue(t_list *node_b, t_list *a)
{
	t_list	*node_a;

	node_a = a;
	if (node_b->val < lst_min(a)->val)
		return (lst_min(a));
	if (node_b->val > lst_max(a)->val)
		return (lst_min(a));
	if (node_b->val > lst_last(a)->val && node_b->val < node_a->val)
		return (node_a);
	node_a = node_a->next;
	while (node_a->next)
	{
		if (node_b->val < node_a->val && node_b->val > node_a->prev->val)
			return (node_a);
		node_a = node_a->next;
	}
	return (node_a);
}

static void	align(t_list *node_b, t_ps *ps)
{
	if (dtt(node_b) > 0 && dtt(homologue(node_b, ps->a)) > 0)
	{
		while (ps->b != node_b && ps->a != homologue(node_b, ps->a))
			do_op(RR, ps);
	}
	else if (dtt(node_b) < 0 && dtt(homologue(node_b, ps->a)) < 0)
	{
		while (ps->b != node_b && ps->a != homologue(node_b, ps->a))
			do_op(RRR, ps);
	}
	if (dtt(node_b) > 0)
		while (ps->b != node_b)
			do_op(RB, ps);
	else
		while (ps->b != node_b)
			do_op(RRB, ps);
	if (dtt(homologue(node_b, ps->a)) > 0)
		while (ps->a != homologue(node_b, ps->a))
			do_op(RA, ps);
	else
		while (ps->a != homologue(node_b, ps->a))
			do_op(RRA, ps);
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
	while (lst_size(ps->a) > 2)
		do_op(PB, ps);
	while (ps->b)
	{
		align(find_min_cost(ps), ps);
		do_op(PA, ps);
	}
	if (dtt(lst_min(ps->a)) > 0)
		while (ps->a != lst_min(ps->a))
			do_op(RA, ps);
	else
		while (ps->a != lst_min(ps->a))
			do_op(RRA, ps);
}
